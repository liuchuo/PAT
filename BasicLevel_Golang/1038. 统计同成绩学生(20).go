package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		N      int
		score  = []string{}
		search = []string{}
		n      [101]int
	)
	fmt.Scanln(&N)
	inputReader := bufio.NewReader(os.Stdin)
	if input1, err1 := inputReader.ReadString('\n'); err1 == nil {
		score = strings.Fields(input1)
	}
	if input2, err2 := inputReader.ReadString('\n'); err2 == nil {
		search = strings.Fields(input2)
	}
	for _, v := range score {
		if cur, err := strconv.Atoi(v); err == nil {
			n[cur]++
		}
	}
	w1 := bufio.NewWriter(os.Stdout)
	for i := 1; i < len(search); i++ {
		if i != 1 {
			w1.WriteString(" ")
		}
		cur, _ := strconv.Atoi(search[i])
		w1.WriteString(fmt.Sprintf("%d", n[cur]))
	}
	w1.Flush()
}

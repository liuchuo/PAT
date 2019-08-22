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
		N               int
		grade           [100001]int
		maxid, maxgrade int
	)
	fmt.Scanln(&N)
	inputReader := bufio.NewReader(os.Stdin)
	for i := 0; i < N; i++ {
		input, _ := inputReader.ReadString('\n')
		t := strings.Fields(input)
		id, _ := strconv.Atoi(t[0])
		g, _ := strconv.Atoi(t[1])
		grade[id] += g
	}
	for k, v := range grade {
		if v > maxgrade {
			maxid, maxgrade = k, v
		}
	}
	fmt.Println(maxid, maxgrade)
}

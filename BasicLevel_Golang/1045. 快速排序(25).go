package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var (
		N       int
		a, b, c []int
		max     int
	)
	fmt.Scanln(&N)
	inputReader := bufio.NewReader(os.Stdin)
	t, err := inputReader.ReadString('\n')
	if err != nil {
		fmt.Println("can't read numbers!")
	}
	str := strings.Fields(t)
	for _, v := range str {
		num, err := strconv.Atoi(v)
		if err != nil {
			fmt.Println("convert to int error!")
		}
		a, b = append(a, num), append(b, num)
	}
	sort.Ints(b)
	for k, v := range b {
		if v == a[k] && a[k] > max {
			c = append(c, v)
		}
		if a[k] > max {
			max = a[k]
		}
	}
	fmt.Println(len(c))
	w1 := bufio.NewWriter(os.Stdout)
	for k, v := range c {
		if k != 0 {
			w1.WriteString(fmt.Sprintf(" "))
		}
		w1.WriteString(fmt.Sprintf("%d", v))
	}
	w1.Flush()
	fmt.Printf("\n")
}

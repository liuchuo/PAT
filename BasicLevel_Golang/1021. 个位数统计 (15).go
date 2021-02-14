package main

import (
	"fmt"
)

func main() {
	var (
		n   string
		num [10]int
	)
	fmt.Scanln(&n)
	//n = "100311"
	for _, v := range n {
		num[int(v-'0')]++
	}
	for k, v := range num {
		if v == 0 {
			continue
		}
		fmt.Printf("%d:%d\n", k, v)
	}
}

package main

import (
	"fmt"
)

func main() {
	var (
		num int
		n   []int
	)
	fmt.Scanln(&num)
	for i := 0; i < 3; i++ {
		n = append(n, num%10)
		num = num / 10
	}
	for i := 0; i < n[2]; i++ {
		fmt.Printf("B")
	}
	for i := 0; i < n[1]; i++ {
		fmt.Printf("S")
	}
	for i := 0; i < n[0]; i++ {
		fmt.Printf("%d", i+1)
	}
}

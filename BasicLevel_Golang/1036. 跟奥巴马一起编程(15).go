package main

import (
	"fmt"
)

func main() {
	var (
		N int
		C string
	)
	fmt.Scanln(&N, &C)
	for i := 0; i < N; i++ {
		fmt.Printf("%s", C)
	}
	fmt.Printf("\n")
	for i := 0; i < N/2+N%2-2; i++ {
		for j := 0; j < N; j++ {
			if j == 0 {
				fmt.Printf("%s", C)
			} else if j == N-1 {
				fmt.Printf("%s\n", C)
			} else {
				fmt.Printf(" ")
			}
		}
	}
	for i := 0; i < N; i++ {
		fmt.Printf("%s", C)
	}
}

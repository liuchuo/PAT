package main

import "fmt"

func main() {
	var (
		N, n   int
		symbol string
	)
	fmt.Scanln(&N, &symbol)
	for n = 1; n*n <= (N+1)/2; n++ {
	}
	n--
	for i := n; i > 0; i-- {
		for j := 0; j < n-i; j++ {
			fmt.Printf(" ")
		}
		for k := 0; k < 2*i-1; k++ {
			fmt.Printf("%s", symbol)
		}
		fmt.Printf("\n")
	}
	for i := 2; i <= n; i++ {
		for j := 0; j < n-i; j++ {
			fmt.Printf(" ")
		}
		for k := 0; k < 2*i-1; k++ {
			fmt.Printf("%s", symbol)
		}
		fmt.Printf("\n")
	}
	fmt.Println(N - n*n*2 + 1)
}

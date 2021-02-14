package main

import "fmt"

func main() {
	var (
		a, b int
		flag int
	)
	input, _ := fmt.Scanf("%d %d", &a, &b)
	for input == 2 {
		if b != 0 {
			if flag == 1 {
				fmt.Printf(" ")
			}
			fmt.Printf("%d %d", a*b, b-1)
			flag = 1
		}
		input, _ = fmt.Scanf("%d %d", &a, &b)
	}
	if flag == 0 {
		fmt.Printf("0 0")
	}
}

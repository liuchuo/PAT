package main

import "fmt"

func main() {
	var n, i int
	fmt.Scanln(&n)
	for ; n > 1; i++ {
		if n%2 == 0 {
			n = n / 2
		} else {
			n = (3*n + 1) / 2
		}
	}
	fmt.Println(i)
}

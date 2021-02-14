package main

import "fmt"

func main() {
	var (
		a, b, c int64
		num     int
	)
	fmt.Scanln(&num)
	for i := 0; i < num; i++ {
		fmt.Scanf("%d %d %d", &a, &b, &c)
		fmt.Printf("Case #%d: %t\n", i+1, a+b > c)
	}
}

package main

import "fmt"

func main() {
	var (
		a, b, d int
		sum     int
		num     []int
	)
	fmt.Scanln(&a, &b, &d)
	sum = a + b
	if sum == 0 {
		fmt.Print(0)
		return
	}
	for sum != 0 {
		num = append(num, sum%d)
		sum /= d
	}
	for i := len(num) - 1; i >= 0; i-- {
		fmt.Printf("%d", num[i])
	}
}

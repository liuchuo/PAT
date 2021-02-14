package main

import "fmt"

func main() {
	var (
		sell, buy string
		num       [256]int
		result    int
	)
	fmt.Scanln(&sell)
	fmt.Scanln(&buy)
	for _, v := range sell {
		num[v]++
	}
	for _, v := range buy {
		if num[v] > 0 {
			num[v]--
		} else {
			result++
		}
	}
	if result != 0 {
		fmt.Println("No", result)
	} else {
		fmt.Println("Yes", len(sell)-len(buy))
	}
}

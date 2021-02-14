package main

import "fmt"

func main() {
	var a [10]int
	fmt.Scanln(&a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9])
	for i := 1; i < 10; i++ {
		if a[i] != 0 {
			fmt.Printf("%d", i)
			a[i]--
			break
		}
	}
	for k, v := range a {
		if v != 0 {
			for j := 0; j < v; j++ {
				fmt.Printf("%d", k)
			}
		}
	}
}

package main

import "fmt"

func isprime(a int) bool {
	for i := 2; i*i <= a; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var (
		num   int
		old   = 3
		count int
	)
	fmt.Scanln(&num)
	for i := 5; i <= num; i = i + 2 {

		if isprime(i) {
			if i-old == 2 {
				count++
			}
			old = i
		}
	}
	fmt.Println(count)
}

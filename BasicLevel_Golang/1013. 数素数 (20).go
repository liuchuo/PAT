package main

import "fmt"

func isPrime(num int) bool {
	for i := 2; i*i <= num; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var (
		p, m, n int
		count   int
	)
	fmt.Scanln(&m, &n)
	for p = 2; count < m-1; p++ {
		if isPrime(p) {
			count++
		}
	}
	for ; count < n; p++ {
		if isPrime(p) {
			count++
			if (count+1-m)%10 == 0 || count == n {
				fmt.Printf("%d\n", p)
			} else {
				fmt.Printf("%d ", p)
			}
		}
	}
}

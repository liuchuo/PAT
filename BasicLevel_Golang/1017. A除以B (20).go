package main

import "fmt"

func main() {
	var (
		a string
		b int
		q []rune
		r int
	)
	fmt.Scanln(&a, &b)
	for _, v := range a {
		n := r*10 + int(v-'0')
		q = append(q, rune(n/b))
		r = n % b
	}
	for k, v := range q {
		if k == 0 && v == 0 && len(q) != 1 {
			continue
		}
		fmt.Printf("%v", v)
	}
	fmt.Printf(" %d", r)
}

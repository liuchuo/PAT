package main

import "fmt"

func main() {
	var (
		str = []string{}
		s   string
		n   int
	)
	n, _ = fmt.Scanf("%s", &s)
	for n == 1 {
		str = append(str, s)
		n, _ = fmt.Scanf("%s", &s)
	}
	for i := len(str) - 1; i > 0; i-- {
		fmt.Printf("%s ", str[i])
	}
	fmt.Printf("%s", str[0])
}

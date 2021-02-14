package main

import (
	"fmt"
	"strings"
)

func main() {
	var (
		str                   string
		countt, countp, count int
	)
	fmt.Scanln(&str)
	countt = strings.Count(str, "T")
	for _, v := range str {
		if v == 'P' {
			countp++
		}
		if v == 'T' {
			countt--
		}
		if v == 'A' {
			count = count + countp*countt
		}
	}
	fmt.Println(count % 1000000007)
}

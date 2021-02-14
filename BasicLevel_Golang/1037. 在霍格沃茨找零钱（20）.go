package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var (
		P, A string
		back int
	)
	fmt.Scanln(&P, &A)
	shoud := money(P)
	real := money(A)
	if real < shoud {
		fmt.Printf("-")
		back = shoud - real
	} else {
		back = real - shoud
	}
	fmt.Printf("%d.%d.%d", back/(17*29), back%(17*29)/29, back%(17*29)%29)
}

//money 返回全部换算成纳特之后的总钱数
func money(str string) int {
	var intSlice []int
	for _, v := range strings.Split(str, ".") {
		tmp, err := strconv.Atoi(v)
		if err == nil {
			intSlice = append(intSlice, tmp)
		}
	}
	sum := intSlice[0]*17*29 + intSlice[1]*29 + intSlice[2]
	return sum
}

package main

import "fmt"

func main() {
	var (
		A, B string
		C    []string
	)
	fmt.Scanln(&A, &B)
	numA, numB := reverseString(A), reverseString(B)
	if len(numA) > len(numB) {
		for len(numA)-len(numB) > 0 {
			numB = append(numB, rune('0'))
		}
	} else {
		for len(numB)-len(numA) > 0 {
			numA = append(numA, rune('0'))
		}
	}
	str := "0123456789JQK"
	for k, v := range numA {
		if k%2 == 0 {
			C = append(C, string(str[(v-'0'+numB[k]-'0')%13]))
		} else {
			temp := numB[k] - v
			if temp < 0 {
				temp = temp + 10
			}
			C = append(C, string(str[temp]))
		}
	}
	for i := len(C) - 1; i >= 0; i-- {
		fmt.Printf("%s", C[i])
	}
}

func reverseString(s string) []rune {
	runes := []rune(s)
	for from, to := 0, len(runes)-1; from < to; from, to = from+1, to-1 {
		runes[from], runes[to] = runes[to], runes[from]
	}
	return runes
}

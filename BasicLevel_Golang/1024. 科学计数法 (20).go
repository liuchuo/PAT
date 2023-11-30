package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var (
		s string
		i int
	)
	fmt.Scanln(&s)
	//s = "-1.234000E+05"
	//s = "-1.2E+10"
	for s[i] != 'E' {
		i++
	}
	t := s[1:i]
	n, _ := strconv.ParseFloat(s[i+1:], 64)
	//fmt.Println(n)
	//fmt.Println(reflect.TypeOf(t))
	if s[0] == '-' {
		fmt.Printf("%c", s[0])
	}
	if n < 0 {
		fmt.Printf("0.")
		for j := 0; j < int(math.Abs(n)-1); j++ {
			fmt.Printf("0")
		}
		for j := 0; j < len(t); j++ {
			if t[j] != '.' {
				fmt.Printf("%c", t[j])
			}
		}
	} else {
		fmt.Printf("%c", t[0])
		var count, j int
		for j = 2; j < len(t) && count < int(n); j++ {
			fmt.Printf("%c", t[j])
			count++
		}
		if j == len(t) {
			for k := 0; k < int(n)-count; k++ {
				fmt.Printf("0")
			}
		} else {
			fmt.Printf(".")
			for k := j; k < len(t); k++ {
				fmt.Printf("%c", t[k])
			}
		}
	}

}

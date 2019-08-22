package main

import (
	"fmt"
	"math"
)

func main() {
	var (
		a, b           string
		da, db         rune
		counta, countb int
		pa, pb         int
	)
	fmt.Scanln(&a, &da, &b, &db)
	for _, v := range a {
		//fmt.Println(v)
		if v == da+48 {
			pa += int(da) * int(math.Pow10(counta))
			counta++
		}
	}
	for _, v := range b {
		if v == db+48 {
			pb += int(db) * int(math.Pow10(countb))
			countb++
		}
	}
	fmt.Println(pa + pb)
}

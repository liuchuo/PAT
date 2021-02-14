package main

import (
	"fmt"
	"sort"
)

type mooncake struct {
	storage, price, unitprice float64
}

func main() {
	var (
		n     int
		d     float64
		cake  = []mooncake{}
		total float64
	)
	fmt.Scanln(&n, &d)
	for i := 0; i < n; i++ {
		var s float64
		fmt.Scanf("%f", &s)
		cake = append(cake, mooncake{s, 0, 0})
	}
	for i := 0; i < n; i++ {
		var p float64
		fmt.Scanf("%f", &p)
		cake[i].price, cake[i].unitprice = p, p/cake[i].storage
	}
	sort.SliceStable(cake, func(i, j int) bool {
		return cake[i].unitprice > cake[j].unitprice
	})

	for i := 0; i < n && d != 0; i++ {
		if cake[i].storage <= d {
			total += cake[i].price
		} else {
			total += cake[i].unitprice * d
			break
		}
		d = d - cake[i].storage
	}
	fmt.Printf("%.2f", total)
}

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	var (
		n         string
		chu, bchu int
		result    int
	)
	fmt.Scanln(&n)
	//n = "1111"
	for result != 6174 && n != "0" {
		var a []int
		if len(n) == 1 {
			a = append(a, 0, 0, 0)
		} else if len(n) == 2 {
			a = append(a, 0, 0)
		} else if len(n) == 3 {
			a = append(a, 0)
		}
		for _, v := range n {
			a = append(a, int(v-'0'))
		}
		sort.Ints(a)
		bchu = a[3]*1000 + a[2]*100 + a[1]*10 + a[0]
		chu = a[0]*1000 + a[1]*100 + a[2]*10 + a[3]
		result = bchu - chu
		fmt.Printf("%04d - %04d = %04d\n", bchu, chu, result)
		n = strconv.Itoa(result)
	}

}

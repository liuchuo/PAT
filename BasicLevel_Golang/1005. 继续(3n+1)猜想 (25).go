package main

import (
	"fmt"
	"sort"
)

func main() {
	var (
		num    int
		series []int
		cover  = map[int]int{}
		tmp    int
		result []int
	)
	fmt.Scanln(&num)
	for i := 0; i < num; i++ {
		fmt.Scanf("%d", &tmp)
		series = append(series, tmp)
		for tmp > 1 {
			if tmp%2 == 0 {
				tmp = tmp / 2
			} else {
				tmp = (3*tmp + 1) / 2
			}
			if cover[tmp] == 1 {
				break
			} else {
				cover[tmp] = 1
			}
		}
	}
	sort.Ints(series)
	for i := 0; i < len(series); i++ {
		if cover[series[i]] == 1 {
			continue
		}
		result = append(result, series[i])
	}
	for i := len(result) - 1; i > 0; i-- {
		fmt.Printf("%d ", result[i])
	}
	fmt.Printf("%d", result[0])

}

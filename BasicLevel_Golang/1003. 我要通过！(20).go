package main

import (
	"fmt"
)

func main() {
	var num int
	var str string
	fmt.Scanf("%d\n", &num)
	for i := 0; i < num; i++ {
		var (
			pos   int
			count [3]int
		)
		fmt.Scanln(&str)
		//str = "APAAATAA"
		for _, v := range str {
			if v == 'A' {
				count[pos]++
			} else if v == 'P' && pos == 0 {
				pos = 1
			} else if v == 'T' && pos == 1 {
				pos = 2
			} else {
				break
			}
		}
		if pos == 2 && count[1] != 0 && count[2] == count[1]*count[0] {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

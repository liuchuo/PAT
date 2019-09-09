package main

import (
	"fmt"
)

func main() {
	var (
		N   int
		win [2]int
	)
	fmt.Scanln(&N)
	for i := 0; i < N; i++ {
		var jiahan, jiahua, yihan, yihua int
		fmt.Scanln(&jiahan, &jiahua, &yihan, &yihua)
		count := jiahan + yihan
		if jiahua == count && yihua != count {
			win[1]++
		}
		if yihua == count && jiahua != count {
			win[0]++
		}
	}
	fmt.Println(win[0], win[1])

}

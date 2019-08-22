package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func findMax(a [3]int) int {
	var max, index int
	for k, v := range a {
		if v > max {
			max = v
			index = k
		}
	}
	return index
}

func main() {
	var (
		n             int
		jiawin, yiwin int
		jia, yi       [3]int
		str           = "BCJ"
	)
	// 用fmt读取输入会有测试点超时
	inputReader := bufio.NewReader(os.Stdin)
	fmt.Scanln(&n)
	for i := 0; i < n; i++ {
		s, _ := inputReader.ReadString('\n')
		t := strings.Fields(s)
		if t[0] == "B" && t[1] == "C" {
			jia[0]++
		} else if t[0] == "B" && t[1] == "J" {
			yi[2]++
		} else if t[0] == "C" && t[1] == "B" {
			yi[0]++
		} else if t[0] == "C" && t[1] == "J" {
			jia[1]++
		} else if t[0] == "J" && t[1] == "B" {
			jia[2]++
		} else if t[0] == "J" && t[1] == "C" {
			yi[1]++
		}
	}
	jiawin = jia[0] + jia[1] + jia[2]
	yiwin = yi[0] + yi[1] + yi[2]
	fmt.Println(jiawin, n-jiawin-yiwin, yiwin)
	fmt.Println(yiwin, n-jiawin-yiwin, jiawin)
	fmt.Printf("%c %c", str[findMax(jia)], str[findMax(yi)])
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var (
		bad, str string
		flag     int
	)
	fmt.Scanln(&bad)
	fmt.Scanln(&str)

	//在循环外判断可以减少时间复杂度
	if strings.Contains(bad, "+") {
		flag = 1
	}

	//循环内如何使用fmt.Print系列函数输出，提交结果随机，最后一个测试点可能过可能不过
	buf := bufio.NewWriter(os.Stdout)
	for _, v := range str {
		if v >= 'A' && v <= 'Z' && flag == 1 {
			continue
		}
		if v >= 'a' && v <= 'z' && strings.Contains(bad, strings.ToUpper(string(v))) {
			continue
		}
		if strings.Contains(bad, string(v)) {
			continue
		}
		buf.WriteString(string(v))
	}
	buf.Flush()
}

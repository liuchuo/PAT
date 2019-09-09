package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		N int
		a = [13]string{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}
		b = [13]string{"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
	)
	fmt.Scanln(&N)
	inputReader := bufio.NewReader(os.Stdin)
	for i := 0; i < N; i++ {
		t, err := inputReader.ReadString('\n')
		if err != nil {
			fmt.Println("Read error")
		}
		t = strings.TrimSpace(t)
		if t[0] >= '0' && t[0] <= '9' {
			tmp, err1 := strconv.Atoi(t)
			if err1 != nil {
				fmt.Println("conert error")
			}
			if tmp/13 != 0 {
				fmt.Printf("%s", b[tmp/13])
			}
			if tmp/13 != 0 && tmp%13 != 0 {
				fmt.Printf(" ")
			}
			if tmp%13 != 0 || tmp == 0 {
				fmt.Printf("%s", a[tmp%13])
			}
			fmt.Printf("\n")
		} else {
			var t1, t2 int
			num := strings.Fields(t)
			if len(num) == 1 {
				num = append(num, "")
			}
			for j := 1; j < 13; j++ {
				if num[0] == a[j] || num[1] == a[j] {
					t2 = j
				}
				if num[0] == b[j] {
					t1 = j
				}
			}
			fmt.Printf("%d\n", t1*13+t2)
		}
	}
}

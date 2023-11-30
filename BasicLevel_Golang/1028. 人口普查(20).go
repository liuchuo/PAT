package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type person struct {
	name  string
	birth string
}

func main() {
	var (
		N, count         int
		oldest, youngest string
		maxbirth         = "1814/09/06"
		minbirth         = "2014/09/06"
	)
	fmt.Scanln(&N)
	inputReader := bufio.NewReader(os.Stdin)
	for i := 0; i < N; i++ {
		input, _ := inputReader.ReadString('\n')
		str := strings.Fields(input)
		if str[1] >= "1814/09/06" && str[1] <= "2014/09/06" {
			count++
			if str[1] >= maxbirth {
				maxbirth, oldest = str[1], str[0]
			}
			if str[1] <= minbirth {
				minbirth, youngest = str[1], str[0]
			}
		}
	}
	fmt.Printf("%d", count)
	if count != 0 {
		fmt.Printf(" %s %s", youngest, oldest)
	}
}

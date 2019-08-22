package main

import (
	"fmt"
	"strconv"
)

func main() {
	num := map[rune]string{
		'0': "ling",
		'1': "yi",
		'2': "er",
		'3': "san",
		'4': "si",
		'5': "wu",
		'6': "liu",
		'7': "qi",
		'8': "ba",
		'9': "jiu",
	}
	var (
		n   string
		sum int
	)
	//n = "1234567890987654321123456789"
	fmt.Scanln(&n)
	for _, k := range n {
		sum = sum + int(k) - 48
	}
	str := strconv.Itoa(sum)
	for i, k := range str {
		if i == len(str)-1 {
			fmt.Printf("%s", num[k])
			break
		}
		fmt.Printf("%s ", num[k])
	}
}

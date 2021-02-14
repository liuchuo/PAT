package main

import (
	"fmt"
	"unicode"
)

func main() {
	var (
		str  [4]string
		i, j int
		week = map[byte]string{
			'A': "MON",
			'B': "TUE",
			'C': "WED",
			'D': "THU",
			'E': "FRI",
			'F': "SAT",
			'G': "SUN",
		}
	)

	for i = 0; i < 4; i++ {
		fmt.Scanln(&str[i])
	}

	for i = 0; i < len(str[0]) && i < len(str[1]); i++ {
		if str[0][i] == str[1][i] && (str[0][i] <= 'G' && str[0][i] >= 'A') {
			fmt.Printf("%s ", week[str[0][i]])
			break
		}
	}
	i = i + 1
	for ; i < len(str[0]) && i < len(str[1]); i++ {
		if str[0][i] == str[1][i] {
			if unicode.IsDigit(rune(str[0][i])) {
				fmt.Printf("%02d:", str[0][i]-'0')
				break
			}
			if str[0][i] >= 'A' && str[0][i] <= 'N' {
				fmt.Printf("%02d:", str[0][i]-'A'+10)
				break
			}
		}
	}
	for j = 0; j < len(str[2]) && j < len(str[3]); j++ {
		if str[2][j] == str[3][j] && unicode.IsLetter(rune(str[2][j])) {
			fmt.Printf("%02d", j)
		}
	}
}

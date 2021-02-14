package main

import (
	"fmt"
	"strings"
)

func main() {
	var (
		real, fake string
		str        []rune
	)
	fmt.Scanf("%s\n%s", &real, &fake)
	real, fake = strings.ToUpper(real), strings.ToUpper(fake)
	for _, v := range real {
		if strings.Index(fake, string(v)) == -1 && strings.Index(string(str), string(v)) == -1 {
			str = append(str, v)
		}
	}
	for _, v := range str {
		fmt.Printf("%c", v)
	}
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var (
		str    string
		count  int
		letter rune
	)
	inputReader := bufio.NewReader(os.Stdin)
	str, _ = inputReader.ReadString('\n')
	Lower := strings.ToLower(str)
	count, letter = strings.Count(Lower, "a"), 'a'
	for i := 'b'; i <= 'z'; i++ {
		tmp := strings.Count(Lower, string(i))
		if tmp > count {
			letter, count = i, tmp
		}
	}
	fmt.Printf("%c %d", letter, count)
}

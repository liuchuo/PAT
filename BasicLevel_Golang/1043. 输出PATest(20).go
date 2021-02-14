package main

import (
	"fmt"
	"strings"
)

func main() {
	var (
		str   string
		count int
	)
	fmt.Scanln(&str)
	//str = "redlesPayBestPATTopTeePHPereatitAPPT"
	P, A, T := strings.Count(str, "P"), strings.Count(str, "A"), strings.Count(str, "T")
	e, s, t := strings.Count(str, "e"), strings.Count(str, "s"), strings.Count(str, "t")
	count = P + A + T + e + s + t
	for i := 0; i < count; i++ {
		if P > 0 {
			fmt.Printf("P")
			P--
		}
		if A > 0 {
			fmt.Printf("A")
			A--
		}
		if T > 0 {
			fmt.Printf("T")
			T--
		}
		if e > 0 {
			fmt.Printf("e")
			e--
		}
		if s > 0 {
			fmt.Printf("s")
			s--
		}
		if t > 0 {
			fmt.Printf("t")
			t--
		}
	}
}

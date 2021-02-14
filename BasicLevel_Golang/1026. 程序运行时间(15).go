package main

import "fmt"

func main() {
	var c1, c2 int
	fmt.Scanln(&c1, &c2)
	sum := (c2 - c1 + 50) / 100
	fmt.Printf("%02d:%02d:%02d", sum/3600, (sum%3600)/60, sum%60)
}

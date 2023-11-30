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
		N   int
		sum float64
	)
	fmt.Scanln(&N)
	inputReader := bufio.NewReader(os.Stdin)
	series, err := inputReader.ReadString('\n')
	if err != nil {
		fmt.Printf("read string error")
	}
	num := strings.Fields(series)
	for i := 1; i <= N; i++ {
		t, _ := strconv.ParseFloat(num[i-1], 64)
		sum += t * float64(i*(N-i+1))
	}
	fmt.Printf("%.2f", sum)
}

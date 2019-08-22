package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var (
		N, p  int
		seq   []int
		count int
	)
	fmt.Scanln(&N, &p)
	inputReader := bufio.NewReader(os.Stdin)
	input, _ := inputReader.ReadString('\n')
	s := strings.Fields(input)
	for _, v := range s {
		num, _ := strconv.Atoi(v)
		seq = append(seq, num)
	}
	sort.Ints(seq)
	for i := 0; i < N; i++ {
		for j := i + count; j < N; j++ {
			if seq[j] <= seq[i]*p && (j-i+1) > count {
				count = j - i + 1
			} else {
				break
			}
		}
	}
	fmt.Println(count)
}

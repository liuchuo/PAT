package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type node struct {
	data string
	next string
}

func main() {
	var (
		address  string
		n, k, n1 int
		memory   = map[string]node{}
		list     = []string{}
	)
	fmt.Scanln(&address, &n1, &k)
	inputReader := bufio.NewReader(os.Stdin)
	for i := 0; i < n1; i++ {
		s, _ := inputReader.ReadString('\n')
		t := strings.Fields(s)
		memory[t[0]] = node{t[1], t[2]}
	}
	for ; memory[address].next != "-1"; n++ {
		list = append(list, address)
		address = memory[address].next
	}
	n, list = n+1, append(list, address)
	for i := 0; i < n-n%k; i += k {
		for j, k := i, i+k-1; j < k; j, k = j+1, k-1 {
			list[j], list[k] = list[k], list[j]
		}
	}
	buf := bufio.NewWriter(os.Stdout)
	for i := 0; i < n-1; i++ {
		buf.WriteString(fmt.Sprintf("%s %s %s\n", list[i], memory[list[i]].data, list[i+1]))
	}
	buf.Flush()
	fmt.Println(list[n-1], memory[list[n-1]].data, "-1")
}

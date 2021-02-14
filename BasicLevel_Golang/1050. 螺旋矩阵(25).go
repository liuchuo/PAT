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
		N      int
		series []int
		result [][]int
	)
	fmt.Scanln(&N)
	r := bufio.NewReader(os.Stdin)
	input, err1 := r.ReadString('\n')
	if err1 != nil {
		fmt.Println("Read numbers error")
	}
	s := strings.Fields(strings.TrimRight(input, "\n"))
	for _, v := range s {
		num, err2 := strconv.Atoi(v)
		if err2 != nil {
			fmt.Println("convert string to int error", v)
		}
		series = append(series, num)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(series)))
	m, n := N, 1
	for ; n <= N/n; n++ {
		if N%n == 0 && N/n-n < m {
			m = N / n
		}
	}
	n = N / m
	w := bufio.NewWriter(os.Stdout)
	for i := 0; i < m; i++ {
		result = append(result, make([]int, n))
	}
	x, y, d := 0, 0, 0
	dx := []int{0, 1, 0, -1}
	dy := []int{1, 0, -1, 0}
	for t := 0; t < N; t++ {
		result[x][y] = series[t]
		nx, ny := x+dx[d], y+dy[d]
		if nx < 0 || nx >= m || ny < 0 || ny >= n || result[nx][ny] != 0 {
			d = (d + 1) % 4
			nx = x + dx[d]
			ny = y + dy[d]
		}
		x = nx
		y = ny
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			w.WriteString(fmt.Sprintf("%d", result[i][j]))
			if j != n-1 {
				w.WriteString(fmt.Sprintf(" "))
			}
		}
		w.WriteString(fmt.Sprintf("\n"))
	}
	w.Flush()
}

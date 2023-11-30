package main

import "fmt"

func main() {
	var (
		n, m int
		arr  = []int{}
	)
	fmt.Scanln(&n, &m)
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Scanf("%d", &tmp)
		arr = append(arr, tmp)
	}
	for j := 0; j < m; j++ {
		arr = append(arr[n-1:], arr[:n-1]...)
	}
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Printf("%d", arr[n-1])
}

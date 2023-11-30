package main

import "fmt"

func isFake(id string) bool {
	var (
		sum       int
		weight    = [...]int{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}
		checkcode = [...]byte{'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'}
	)
	for i := 0; i < 17; i++ {
		if id[i] < '0' || id[i] > '9' {
			return true
		}
		sum += int(id[i]-'0') * weight[i]
	}
	z := sum % 11
	if checkcode[z] != id[17] {
		return true
	}
	return false
}

func main() {
	var (
		N, flag int
		id      string
	)
	fmt.Scanln(&N)
	for i := 0; i < N; i++ {
		fmt.Scanln(&id)
		if isFake(id) {
			fmt.Println(id)
			flag = 1
		}
	}
	if flag == 0 {
		fmt.Println("All passed")
	}
}

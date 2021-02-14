package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var (
		N               int
		group           [1001]int
		winID, winScore int
	)
	fmt.Scanln(&N)
	for i := 0; i < N; i++ {
		var (
			id    string
			score int
		)
		fmt.Scanln(&id, &score)
		groupIDStr := strings.Split(id, "-")
		groupID, err := strconv.Atoi(groupIDStr[0])
		if err != nil {
			fmt.Println("convert string to int error!")
		}
		group[groupID] += score
	}
	for k, v := range group {
		if v > winScore {
			winID, winScore = k, v
		}
	}
	fmt.Println(winID, winScore)

}

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func createIntSlice(str string) []int {
	var intSlice []int
	for _, v := range strings.Fields(str) {
		tmp, err := strconv.Atoi(v)
		if err == nil {
			intSlice = append(intSlice, tmp)
		}
	}
	return intSlice
}

func searchInsertion(ori []int, mid []int) (bool, []int) {
	var i, j int
	for i = 0; i < len(ori)-1 && mid[i] <= mid[i+1]; i++ {
	}
	for j = i + 1; j < len(ori) && ori[j] == mid[j]; j++ {
	}
	sort.Ints(mid[:i+2])
	return j == len(ori), mid
}

func merge(ori []int, mid []int) []int {
    k,flag := 1,true
    for flag {
        flag = false
        for i := 0;i < len(ori);i++ {
            if ori[i] != mid[i] {
                flag = true
            }
        }
        k = k*2
        for i := 0; i < len(ori)/k;i++ {
            sort.Ints(ori[i*k:(i+1)*k])
        }
        sort.Ints(ori[len(ori)/k*k:len(ori)])
    }
	return ori
}

func main() {
	var (
		N                int
		original, middle []int
	)
	fmt.Scanln(&N)
	scanner := bufio.NewScanner(os.Stdin)
	for i := 1; i <= 2 && scanner.Scan(); i++ {
		switch i {
		case 1:
			original = createIntSlice(scanner.Text())
		case 2:
			middle = createIntSlice(scanner.Text())
		}
	}
	//N = 10
	//ori = "3 1 2 8 7 5 9 4 0 6"
	//mid = "1 2 3 4 5 7 8 9 0 6 "
	copyMiddle := make([]int, len(middle))
	copy(copyMiddle, middle)
	if truth, next := searchInsertion(original, middle); truth {
		fmt.Println("Insertion Sort")
		for k, v := range next {
			if k != 0 {
                fmt.Printf(" ")
            }
			fmt.Printf("%d", v)
		}
	} else {
		fmt.Println("Merge Sort")
		result := merge(original, copyMiddle)
		for k, v := range result {
			if k != 0 {
                fmt.Printf(" ")
            }
			fmt.Printf("%d", v)
		}
	}
}

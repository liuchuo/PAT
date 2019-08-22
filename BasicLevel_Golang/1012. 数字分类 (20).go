package main

import "fmt"

func main() {
	var (
		tmp, num int
		sum      [5]int
		count    [5]int
	)
	fmt.Scanf("%d", &num)
	for i := 0; i < num; i++ {
		fmt.Scanf("%d", &tmp)
		switch tmp % 5 {
		case 0:
			if tmp%2 == 0 {
				count[0]++
				sum[0] = sum[0] + tmp
			}
		case 1:
			count[1]++
			if count[1]%2 == 1 {
				sum[1] = sum[1] + tmp
			} else {
				sum[1] = sum[1] - tmp
			}
		case 2:
			count[2]++
		case 3:
			sum[3] = sum[3] + tmp
			count[3]++
		case 4:
			count[4]++
			if tmp > sum[4] {
				sum[4] = tmp
			}
		}
	}
	//fmt.Println(count,sum)
	for i := 0; i < 4; i++ {
		if count[i] == 0 {
			fmt.Printf("N ")
			continue
		}
		switch i {
		case 0:
			fmt.Printf("%d ", sum[0])
		case 1:
			fmt.Printf("%d ", sum[1])
		case 2:
			fmt.Printf("%d ", count[2])
		case 3:
			fmt.Printf("%.1f ", float32(sum[3])/float32(count[3]))
		}
	}
	if count[4] != 0 {
		fmt.Printf("%d", sum[4])
	} else {
		fmt.Printf("N")
	}

}

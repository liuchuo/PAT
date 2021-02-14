package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

//L is student level weight
const L = 100000000000000

//S is student grade weight
const S = 100000000000

//D is student id weight
const D = 100000000

func main() {
	var (
		n, l, h           int
		id, de, cai       int
		sum, level, count int
		student           []int64
	)
	fmt.Scanln(&n, &l, &h)
	inputReader := bufio.NewReader(os.Stdin)
	for i := 0; i < n; i++ {
		s, _ := inputReader.ReadString('\n')
		t := strings.Fields(s)
		id, _ = strconv.Atoi(string(t[0]))
		de, _ = strconv.Atoi(string(t[1]))
		cai, _ = strconv.Atoi(string(t[2]))
		//fmt.Scanln(&id, &de, &cai)
		if de >= l && cai >= l {
			sum = de + cai
			if de >= h && cai >= h {
				level = 4
			} else if de >= h && cai < h {
				level = 3
			} else if de < h && cai < h && de >= cai {
				level = 2
			} else {
				level = 1
			}
			tmp := level*L + sum*S + de*D + D - id
			student = append(student, int64(tmp))
			count++
		}
	}

	sort.SliceStable(student, func(i, j int) bool {
		return student[i] > student[j]
	})

	fmt.Println(count)
	buf := bufio.NewWriter(os.Stdout)
	for i := 0; i < count; i++ {
		id = int(D - student[i]%D)
		sum = int(student[i] % L / S)
		de = int(student[i] % S / D)
		cai = sum - de
		buf.WriteString(fmt.Sprintf("%d %d %d\n", id, de, cai))
	}
	buf.Flush()
}

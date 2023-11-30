package main

import "fmt"

type student struct {
	name  string
	id    string
	grade int
}

func main() {
	var (
		snum        int
		stu         []student
		first, last int
	)
	fmt.Scanln(&snum)
	for i := 0; i < snum; i++ {
		var (
			tname  string
			tid    string
			tgrade int
		)
		fmt.Scanln(&tname, &tid, &tgrade)
		stu = append(stu, student{tname, tid, tgrade})
	}

	for k, v := range stu {
		if v.grade > stu[first].grade {
			first = k
		} else if v.grade < stu[last].grade {
			last = k
		}
	}
	fmt.Println(stu[first].name, stu[first].id)
	fmt.Println(stu[last].name, stu[last].id)
}

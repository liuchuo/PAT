package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

//Student 考生信息
type Student struct {
	id   string
	real int
}

func main() {
	var (
		student = map[string]Student{}
		N, M    int
	)
	fmt.Scanln(&N)
	for i := 0; i < N; i++ {
		var tmpid, tmptest string
		var tmpreal int
		fmt.Scanln(&tmpid, &tmptest, &tmpreal)
		student[tmptest] = Student{tmpid, tmpreal}
	}
	fmt.Scanln(&M)
	inputReader := bufio.NewReader(os.Stdin)
	t, _ := inputReader.ReadString('\n')
	result := strings.Fields(t)
	for _, v := range result {
		fmt.Println(student[v].id, student[v].real)
	}
}

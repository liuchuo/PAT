package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

//Gcd 最大公约数：辗转相除法
func Gcd(x, y int64) int64 {
	x = int64(math.Abs(float64(x)))
	y = int64(math.Abs(float64(y)))

	var tmp int64
	for {
		tmp = (x % y)
		if tmp > 0 {
			x = y
			y = tmp
		} else {
			return y
		}
	}
}

//Lcm 最小公倍数
func Lcm(x, y int64) int64 {
	return (x * y) / Gcd(x, y)
}

//Add 分数加法
func Add(a1, b1, a2, b2 int64) (c1, c2 int64) {
	lcm := Lcm(b1, b2)
	c1 = a1*(lcm/b1) + a2*(lcm/b2)
	c2 = lcm
	return c1, c2
}

//Sub 分数减法
func Sub(a1, b1, a2, b2 int64) (c1, c2 int64) {
	lcm := Lcm(b1, b2)
	c1 = a1*(lcm/b1) - a2*(lcm/b2)
	c2 = lcm
	return c1, c2
}

//Mul 分数乘法
func Mul(a1, b1, a2, b2 int64) (c1, c2 int64) {
	gcd := Gcd(a1*a2, b1*b2)
	c1 = a1 * a2 / gcd
	c2 = b1 * b2 / gcd
	return c1, c2
}

//Div 分数除法
func Div(a1, b1, a2, b2 int64) (c1, c2 int64) {
	c1 = a1 * b2
	c2 = a2 * b1
	if (c1 < 0 && c2 < 0) || (c1 > 0 && c2 < 0) {
		c1, c2 = c1*(-1), c2*(-1)
	}
	return c1, c2
}

//Display 精简显示
func Display(c1, c2 int64) string {
	var flag int
	var str []string
	if c2 == 0 {
		return "Inf"
	}
	if c1 == 0 {
		return "0"
	}
	gcd := Gcd(c1, c2)
	if c1 < 0 {
		str = append(str, "(", "-")
		flag = 1
		c1 *= (-1)
	}
	k := c1 / c2
	a, b := c1/gcd, c2/gcd
	if k != 0 {
		str = append(str, strconv.Itoa(int(k)))
	}
	if k != 0 && b != 1 {
		str = append(str, " ")
	}
	if b != 1 {
		str = append(str, strconv.Itoa(int(a%b)), "/", strconv.Itoa(int(b)))
	}
	if flag == 1 {
		str = append(str, ")")
	}
	result := strings.Join(str, "")
	return result
}

func main() {
	var m, n string
	fmt.Scanln(&m, &n)

	str1 := strings.Split(m, "/")
	a1, _ := strconv.Atoi(str1[0])
	b1, _ := strconv.Atoi(str1[1])
	str2 := strings.Split(n, "/")
	a2, _ := strconv.Atoi(str2[0])
	b2, _ := strconv.Atoi(str2[1])
	c1 := Display(int64(a1), int64(b1))
	c2 := Display(int64(a2), int64(b2))
	s1, s2 := Add(int64(a1), int64(b1), int64(a2), int64(b2))
	fmt.Println(c1, "+", c2, "=", Display(s1, s2))
	d1, d2 := Sub(int64(a1), int64(b1), int64(a2), int64(b2))
	fmt.Println(c1, "-", c2, "=", Display(d1, d2))
	p1, p2 := Mul(int64(a1), int64(b1), int64(a2), int64(b2))
	fmt.Println(c1, "*", c2, "=", Display(p1, p2))
	q1, q2 := Div(int64(a1), int64(b1), int64(a2), int64(b2))
	fmt.Println(c1, "/", c2, "=", Display(q1, q2))
}

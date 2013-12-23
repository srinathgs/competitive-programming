package main

import (
	"fmt"
)

func revNum(x int) int {
	var res int
	for x > 0 {
		res = res*10 + x%10
		x = x / 10
	}
	return res
}

func main() {
	var N int
	fmt.Scanf("%d", &N)
	for ; N > 0; N-- {
		var (
			x int
			y int
		)
		fmt.Scanf("%d", &x)
		fmt.Scanf("%d", &y)
		fmt.Println(revNum(revNum(x) + revNum(y)))
	}
}

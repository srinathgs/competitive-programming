package main

import (
	"fmt"
)

func getZeroes(x int64) int64 {
	var cnt int64
	for x > 0 {
		x = x / 5
		cnt += x
	}
	return cnt
}

func main() {
	var N int
	fmt.Scanf("%d", &N)
	for ; N > 0; N-- {
		var x int64
		fmt.Scanf("%d", &x)
		fmt.Println(getZeroes(x))
	}
}

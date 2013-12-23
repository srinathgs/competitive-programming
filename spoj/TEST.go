package main

import (
	"fmt"
)

func main() {
	var inp int
	for {
		fmt.Scanf("%d", &inp)
		if inp == 42 {
			break
		}
		fmt.Println(inp)
	}
}

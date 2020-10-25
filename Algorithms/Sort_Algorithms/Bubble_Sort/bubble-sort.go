package main

import "fmt"

func BubbleSort(arr []int, n int) ([]int){
	var temp int 
	for i := 1; i < n; i++ {
		for j := 0; j < n-i; j++ {
			if arr[j] > arr[j+1] {
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			}
		}
	}

	return arr
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scanf("%d", &temp)
		arr[i] = temp
	}

	arr = BubbleSort(arr, n)

	fmt.Println("Array after sorting:")
	for i := 0; i < n; i++ {
		fmt.Println(arr[i], " ")
	}

}

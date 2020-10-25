package main

import "testing"

func TestBubbleSort(t *testing.T) {

	if BubbleSort([]int{5, 4, 3, 2, 1}, 5) != []int{5, 4, 3, 2, 1} {
		t.Error("Expected 2 + 2 to equal 4")
	}
}

import java.io.*;
import java.lang.*;

class BinarySearch {

	public static int binary_search(int arr[], int n, int key) {
		int first = 0;
		int last = n - 1;

		while(first < last) {

			int mid = (first + last) / 2;

			if(arr[mid] == key) 
				return mid;

			else if(arr[mid] > key)
				last = mid - 1;

			else 
				first = mid + 1;
		} 

		return -1;
	}

	public static void main(String args[]) {
		
		int n;
		Scanner scan = new Scanner(System.in);

		n = scan.nextInt();
		int[] arr = new int[n];

		for(int i = 0; i < n; i ++) {
			arr[i] = scan.nextInt();
		}

		int key = scan.nextInt();

		int x = binary_search(arr, n, key);

		if(x == -1) 
			System.out.println("Key not found\n");
		else
			System.out.println("Key is found at position " + x);

	}
}
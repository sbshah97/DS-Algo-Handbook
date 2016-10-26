import java.io.*;
import java.util.*;
 
public class Radix {
 
    //get maximum value in arr[]
    static int getMax(int arr[], int n)
    {
        int max = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }
 
    static void countSort(int arr[], int n, int exp)
    {
        int output[] = new int[n]; // output array
        int i,count[] = new int[10];

        Arrays.fill(count,0);
 
        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[ (arr[i]/exp)%10 ]++;
 
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
 
        // Build the output array
        for (i = n - 1; i >= 0; i--)
        {
            output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
            count[ (arr[i]/exp)%10 ]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

    // Radix Sort
    static void radixsort(int arr[], int n)
    {
        //the maximum number to know number of digits
        int m = getMax(arr, n);
 
        for (int exp = 1; m/exp > 0; exp *= 10)
            countSort(arr, n, exp);
    }

    //Driver function to check for above function
    public static void main (String[] args)
    {
	int arr[] = {173, 4, 75, 190, 80, -24, 20, 6},n = arr.length;

        radixsort(arr, n);

        for (int i=0; i<n; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
}

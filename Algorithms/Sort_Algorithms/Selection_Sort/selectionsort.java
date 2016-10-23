/**
 * @Author shrawnz
 * @date   24 October, 2016
 */

import java.util.Scanner;

public class selectionsort
{
	public static void Selection_Sort(int[] arr)
	{
		int i,j,temp,min;

		for(i=0;i<arr.length-1;i++)
		{
			min=i;

			for(j=i+1;j<arr.length;j++)
			{
				if(arr[j]<arr[min])
					{
						min=j;
					}
			}

			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;

		}

	}
	public static void main(String[] args) 
	{
		int n,i;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of array: ");

		n=sc.nextInt();
		int[] arr = new int[n];

		System.out.println("Enter elements: ");
		for(i=0;i<n;i++)
			arr[i]=sc.nextInt();

		Selection_Sort(arr);

		for(i=0;i<n;i++)
			System.out.print(arr[i]+" ");
			
	}	
} 
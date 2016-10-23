/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{

    void search(int arr[], int n, int x)
    {
        int i,flag=1;
        for (i=0; i<n; i++)
        {
            if (arr[i] == x)
            {

                flag=0;
                System.out.println(x + " is present at index "+i);
            }
        }
        if(flag==1)
            System.out.println("Element is not present");
    }
	public static void main (String[] args) throws java.lang.Exception
	{
	    Codechef O =new Codechef();
	    int arr[] = {1, 10, 30, 15};
        int x = 30;
       O.search(arr, arr.length, x);
	}

}


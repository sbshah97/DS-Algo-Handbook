/*Test Case

+  Input:
+  abcbbbbcccbdddadacb

+  Output:
+  bcbbbbcccb
*/

/*Logic
+  Input string variable.

+  Initialize temp_odd = string[1] and temp_even = string[0].
+  Initialize count_start = 0 and count_end = 1.

			+---+
Iterate through the length of the string. i=2; i++;

if
+ Case 1 : MisMatch
+  Then we check for 'c'. Since 'c' does not match temp_odd or temp_even we equalize c to temp_odd.
+  Store both the variables count_start and count_end as successive elements of an calc_array.
+  and increment count_start and count_end.

else
+ Case 2 : Match
+  Next since the variable 'b' matches the input string, we increment count_end.

			+---+

+ Find difference of successive elements in calc_array.
+ Return the successive terms of the array.

+ Use 'str.substring' for the string to print the longest substring.
*/

/*			Pseudocode
+1 Input string[]; j=0; calc_array[]; val=0.
+2 temp_even=string[0]; temp_odd=string[1];
+3 count_start=0; count_end=1;
+4 for i from 2 to string.length-1
+5   if(string[i]!=temp_even || string[i]!=temp_odd)
+6	if(count_start % 2 == 0)
+7	  temp_odd = string[i]
+8	else
+9	  temp_even = string[i]
+10	calc_array[j]=count_start; calc_array[j+1]=count_end;j+=2
+11	count_start++; count_end++.
+12  else
+13	count_end++
+14 for i = 0 to j ; j+=2
+15    if(a[j+1]-a[j] > val)
+16	 count_start=a[j]; count_end=a[j+1]
+17 str.substring(string,count_start,count_end)
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	//Input string
	int i;
	char str[50];
	//for(i = 0 ; str[i] != '\0' ; i ++)
	gets(str);
	int n=0;

	//Find length of string
	for(i = 0; str[i] != '\0' ; i++) 
		n++;	

	//Declare variables
	char temp_even = str[0];
	char temp_odd = str[1];
	int j = 0, calc_array[100], val = 0;
	int count_start = 0, count_end = 1;

	//Iterate through the string
	for (i = 2 ; i < n; i++) {
		if(str[i] != temp_even || str[i] != temp_odd) {
			if(count_start % 2 == 0)
				temp_even = str[i];
			else if(count_start % 2 == 1)
				temp_odd = str[i];
			calc_array[j] = count_start;
			calc_array[j+1] = count_end;
			j += 2;
			count_start ++;
			count_end ++;
		}
		else if(str[i] == temp_even || str[i] == temp_odd)
			count_end ++;
	}

	//Find starting and ending points of maximum sub-array
	for(i = 0 ; i < j ; i +=2) {
		if(calc_array[i+1] - calc_array[i] > val) {
			val = calc_array[i+1] - calc_array[i];
			count_start = calc_array[i];
			count_end = calc_array[i+1];
			//printf("\n%d %d\n", count_start,count_end);
		}
	}

	//Print out the substring
	for(i = count_start; i <= count_end; i++) 
		printf("%c",str[i]);
	printf("\n");

	//printf("%d %d",count_start, count_end);
}

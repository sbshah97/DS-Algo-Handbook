import java.util.Scanner;

public class BubbleSort{

		public static void sort(int[] array){
			  int i, j, temp;
				for(i = 0; i<array.length; ++i)
					for(j = i+1; j<array.length-1; ++j)
						if(array[j] > array[j+1]){
							temp = array[j];
							array[j] = array[j+1];
							array[j+1] = temp;
						}
		}

    public static void main(String[] args) {
    	int n;
			Scanner scan = new Scanner(System.in);

			System.out.println("Enter number of elements: ");
			int size = scan.nextInt();
			int[] myArray = new int[size];

			for(int i = 0; i<size; ++i){
				System.out.print("Enter array element number " + (i+1) + ":");
				myArray[i] = scan.nextInt();
			}
			scan.close();

			sort(myArray);

			for(int j = 0; j<size; ++j)
				System.out.print(myArray[j] + " ");
			
    }
}

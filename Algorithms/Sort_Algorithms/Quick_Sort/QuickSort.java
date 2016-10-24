/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quicksort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

/**
 * QuickSort: A divide and conquer sorting algorithm. Time-complexity: O(n^2)
 * Choose a random element of the list and divide the list whether each element
 * is smaller or larger than the pivot. Sort each sublist and add them together
 * in the right order
 * @author Maarten Terpstra
 */
public class QuickSort {
    static Random r = new Random();

    public static List<Integer> QuickSort(List<Integer> comps)
    {
        // The trivial list is already sorted
        if(comps.size() <= 1)
            return comps;
        // Choose a random pivot
        int pivot = comps.get(r.nextInt(comps.size()));
        
        // Divide the list in either smaller, greater, or equal to the pivot
        List<Integer> less_than    = new ArrayList<>();
        List<Integer> pivots       = new ArrayList<>();
        List<Integer> greater_than = new ArrayList<>();
        
        for(int elem : comps)
        {
            if (elem == pivot)
                pivots.add(elem);
            else if(elem < pivot)
                less_than.add(elem);
            else
                greater_than.add(elem);
        }
        // Sort the greater and smaller lists then add them in order
        less_than = QuickSort(less_than);
        // Add the pivots. These are already sorted.
        less_than.addAll(pivots);
        // Add the elements greater than the pivot
        greater_than = QuickSort(greater_than);
        less_than.addAll(greater_than);
        // And return it
        return less_than;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Initialize a list
        List<Integer> list = Arrays.asList(1,23, 4, 348, 54,2367,5, 21,3, 23);
        // And sort it
        List<Integer> sorted_list = QuickSort(list);
        // Print it
        for(int elem : sorted_list)
            System.out.println(elem);
    }
    
}

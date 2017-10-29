//
//  sortAlgs.hpp
//  hw5
//
//  Created by Vincent Bett on 10/31/16.
//  
// Header file with the function definitions of the sorting algorithms

#ifndef sortAlgs_h
#define sortAlgs_h

#include <stdio.h>
#include <vector>

/*
 FUNCTION: insertionSoer
 PURPOSE: To perform an insertion sort for a vector of integers
 INPUT: an adress of a vector
 OUTPUT: none.
*/
void insertionSort(std::vector<int> &toSort);

/*
 FUNCTION: mergeSort
 PURPOSE: To sort the vector based on the merge sort algorithm
 INPUT: A vector of integers.
 OUTPUT: None
*/
void mergeSort(std::vector<int> &myVect);


/*
 FUNCTION: QuickSort
 PURPOSE: To sort a vector based on the quick sort algorithm
 INPUT: A vector of integers
 OUTPUT: None.
*/
void QuickSort(std::vector<int> &myArray);


#endif /* sortAlgs_h */

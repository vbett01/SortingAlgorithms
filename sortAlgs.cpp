//
//  sortAlgs.cpp
//  hw5
//
//  Created by Vincent Bett on 10/31/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include "sortAlgs.h"
#include <iostream>
using namespace std;


////////////////HELPER FUNCTIONS FOR THE SORTING FUNCTIONS/////////////////////
/*
FUNCTION: QuickSortHelp
PURPOSE: Helper function that helps sort the vector by selectively
sorting parts of the vector.
*/
void QuickSortHelp(std::vector<int> &myArray, unsigned int start,
                                                         unsigned int end);
/*
FUNCTION: Partition.
PURPOSE: To select a pivot and and move all the elements that are
smaller than the pivot to the left of it.
*/
unsigned int Divide(std::vector<int> &myArray, unsigned int start, 
                                                        unsigned int end);

/*
FUNCTION: merge.
PURPOSE: To finally consolidate the sorted vector into one vector.
*/
void merge(std::vector<int> &LargeVect, std::vector<int> &left,
                                                 std::vector<int> &right);

/*
FUNCTION: finishSort.
PURPOSE: To continue consolidatin the leftover parts
of the smaller vectors into the bigger one.
*/
void finishSort(std::vector<int> &left, std::vector<int> &right,
                std::vector<int> &LargeVect, unsigned int leftCount,
                         unsigned int leftSize, unsigned int rightCount,
		                unsigned int rightSize,unsigned int bigCount);

///////////////END OF FUNCTION DECLARATIONS FOR HELPER FUNCTIONS////////////////

/*
FUNCTION: merge.
PURPOSE: To finally consolidate the sorted vector into one vector.
INPUT: Three vectors of integers.
OUTPUT: None
*/
void merge(std::vector<int> &LargeVect, std::vector<int> &left,
                                                 std::vector<int> &right)
{
	unsigned int leftSize = left.size();
	unsigned int rightSize = right.size();
	unsigned int leftCount = 0;
	unsigned int rightCount = 0;
	unsigned int bigCount = 0;
	// start copying the sorted values back to the larger vector from the
	// two smaller vectors.
	while(leftCount < leftSize and rightCount < rightSize)
	{
		if(left[leftCount]<= right[rightCount])
		{
			LargeVect[bigCount] = left[leftCount];
			leftCount++;
		}
		else
		{
			LargeVect[bigCount] = right[rightCount];
			rightCount++;
		}
		bigCount++;

	}
	// If you exhaust one vector before the other. Keep adding the values
        // that remain in the Other vector from left to right.
	finishSort(left, right, LargeVect, leftCount, leftSize, rightCount,
                                                         rightSize, bigCount);

}

/*
FUNCTION: finishSort.
PURPOSE: To continue consolidatin the leftover parts 
of the smaller vectors into the bigger one.
INPUT: Three vectors of ints and three unsigned integers.
OUTPUT: None
*/
void finishSort(vector<int> &left, vector<int> &right, vector<int> &LargeVect, 
	unsigned int leftCount, unsigned int leftSize, unsigned int rightCount,
                                unsigned int rightSize,unsigned int bigCount)
{
	// If one vector was exahausted start adding the values in the 
        // remaining vector to the Sorted vector from left to right.
	while(leftCount < leftSize)
	{
		LargeVect[bigCount] = left[leftCount];
		leftCount++;
		bigCount++;

	}
	while(rightCount < rightSize)
	{
		LargeVect[bigCount] = right[rightCount];
		rightCount++;
		bigCount++;
	}

}

/*
FUNCTION: insertionSort
PURPOSE: To perform an insertion sort for a vector of integers
INPUT: an adress of a vector
OUTPUT: none.
*/
void insertionSort(vector<int> &myVect)
{
	unsigned int numElements =myVect.size();
	for(unsigned int i = 1; i < numElements ; i++)
	{
		int value = myVect[i];
		unsigned int hole = i; // Keep track of where to swap to.
		while(hole > 0 and myVect[hole - 1] > value)
		{
			myVect[hole] = myVect[hole - 1];
			hole = hole - 1;
		}
		myVect[hole] = value;
	}

}

/*
FUNCTION: mergeSort
PURPOSE: To sort the vector based on the merge sort algorithm
INPUT: A vector of integers.
OUTPUT: None
*/
void mergeSort(vector<int> &myVect)
{
	unsigned int size = myVect.size();
	if(size<2)
		return;
	unsigned int mid = size/2;
	vector<int> left(mid);
	vector<int> right(size - mid);
	for(unsigned int i = 0; i<mid ; i++)
	{
		left[i] = myVect[i];
	}
	for(unsigned int j = mid; j<size; j++)
	{
		right[j - mid] = myVect[j];
	}
	// divide the vectors into smaller vectors for easy merging later.
	mergeSort(left);
	mergeSort(right);
	merge(myVect, left, right);

}


/*
FUNCTION: QuickSort
PURPOSE: To sort a vector based on the quick sort algorithm
INPUT: A vector of integers
OUTPUT: None.
*/
void QuickSort(std::vector<int> &myArray)
{
	unsigned int start = 0;
	unsigned int end = myArray.size() - 1;
	QuickSortHelp(myArray, start, end);
}

/*
FUNCTION: QuickSortHelp
PURPOSE: Helper function that helps sort the vector by selectively
sorting parts of the vector.
INPUT: A vector of ints and two unsigned integers.
OUTPUT: None
*/
void QuickSortHelp(std::vector<int> &myArray, unsigned int start,
                                                         unsigned int end)
{
	unsigned int index;
	if(start < end)
	{
		index = Divide(myArray, start, end);
		if(index != 0)
		{
			QuickSortHelp(myArray, start, index-1);
			QuickSortHelp(myArray, index+1, end);
		}
                // we never found an element smaller than the pivot.
                // so we just swapped the pivot and the element in the
                // index.
                if(index == 0)
                {
                        QuickSortHelp(myArray, start, index);
                        QuickSortHelp(myArray, index+1, end);
                }
	}

}

/*
FUNCTION: Partition.
PURPOSE: To select a pivot and and move all the elements that are
smaller than the pivot to the left of it.
INPUT: A vector of integers and two unsigned integers.
OUTPUT: None.
*/
unsigned int Divide(std::vector<int> &myArray, unsigned int start,
                                                         unsigned int end)
{

	int pivot = myArray[end];
	unsigned int Index = start;
	for(unsigned int i = start; i < end; i++)
	{
		if(myArray[i] <= pivot)
		{
			// swap the smaller element with the one in the index
			int temp = myArray[i];
			myArray[i] = myArray[Index];
			myArray[Index] = temp;
			Index++;
		}
	}
	//swap the pivot with the element in the index
	int temp2 = myArray[Index];
	myArray[Index] = myArray[end];
	myArray[end] = temp2;
	return Index;
}

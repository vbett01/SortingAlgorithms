//
//  main.cpp
//  hw5
//
//  Created by Vincent Bett on 10/31/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "sortAlgs.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

// Fuction definitions for the helper functions.
int runInteractive(string method, vector<int> &toSort);
void readFile(string method, vector<int> &toSort);
void sortMethod(string method, vector<int> &toSort);
int readFromFile(string Filename, vector<int> &toSort);
int readNums(istream &infile, vector<int> &toSort);
void outputMethod(string output, vector<int> &toSort,
		 string from, int num_elem, string method);
void print(vector<int> &toSort);
void saveFile(vector<int> &toSort, string Filename,
			 string method, int num_elem);
string convertTostring(int num);
int FindMethodToSolve(string method);

/*
   Main function.
   It's putpose is to launch the program accept user input and sort the
   inputed integers.
 */
int main(int argc, const char * argv[]) {

	string method;
	vector<int> toSort;
	// Check if the user will enter numbers from the command line
	if(argc == 3)
	{
		string method = argv[1];
		string output = argv[2];
		string from = "cin";
		int count = runInteractive(method, toSort);
		outputMethod(output, toSort, from, count, method);
	}
	else if(argc > 4 or argc <3)
	{
		cerr<<" sorter sortAlg outputMode [fileName]"<<endl;
		cerr<<"\t" << "where:  sortAlg is -s1, -s2, or -s3"<<endl;
		cerr<<"\t" <<"and     outputMode is --print or --save"<<endl;
		return 1;

	}
	else // Read the numbers from file.
	{
		string Filename = argv[3];
		string output = argv[2];
		string method = argv[1];
		int count = readFromFile(Filename, toSort);
		if(count == -1)
			return 1;
		sortMethod(method, toSort);
		outputMethod(output, toSort, Filename, count, method);

	}

	return 0;
}

/*
FUNCTION: runInteractive
PURPOSE: To run the program in interactive mode and enter input directly
from the command line.
INPUT: A string and a vector of integers
OUTPUT: None
 */
int runInteractive(string method, vector<int> &toSort)
{
	int count = 0;
	int num;
	while(cin >> num)
	{
		toSort.push_back(num);
		count++;
	}
	sortMethod(method, toSort);
	return count;
}

/*
FUNCTION: sortMethod
PURPOSE: To choose the method of sorting based on the user input
INPUT: A string method and a vector of integers
OUTPUT: None
 */

void sortMethod(string method, vector<int> &toSort)
{
	if(method == "-s1")
	{
		// Run insertion sort
		insertionSort(toSort);

	}
	if(method == "-s2")
	{
		// Run merge sort
		mergeSort(toSort);
	}
	if(method == "-s3")
	{
		// Run quick sort
		QuickSort(toSort);
	}
}


/*
FUNCTION: readFromFile
PURPOSE: To open the input stream and start reading in the 
numbers.
INPUT: A string and a vector of integers
OUTPUT: None
 */
int readFromFile(string Filename, vector<int> &toSort)
{
	ifstream input;
	input.open(Filename);
	if (not input.is_open()) {
		cerr << "Unable to open " << Filename << endl;
		return -1;
	}
	int count = readNums(input, toSort);
	return count;
}

/*
FUNCTION: readNums
PURPOSE: To read the numbers from the inputed file.
INPUT: A file and a vector of ints
OUTPUT: None
 */
int readNums(istream &infile, vector<int> &toSort)
{
	int s;
	int count = 0;
	for (infile >> s; not infile.eof(); infile >> s)
	{
		toSort.push_back(s);
		count++;
	}

	return count;
}

/*
FUNCTION: outputMethod
PURPOSE: To determine the output method to choose based on the 
user selection. Either to the standard output or to a file.
INPUT: A string and a vector of integers
OUTPUT: None.
 */
void outputMethod(string output, vector<int> &toSort, string from,
					 int num_elem, string method)
{
	if(output == "--print")
	{
		print(toSort);
	}
	if(output == "--save")
	{
		saveFile(toSort, from, method, num_elem);
	}
}

/*
FUNCTION: print
PURPOSE: To print the sorted numbers in the standard 
output
INPUT: A vector of integers
OUTPUT: None
 */
void print(vector<int> &toSort)
{
	unsigned int size = toSort.size();

	for (unsigned int i = 0; i< size; i++)
	{
		cout<<toSort[i];
		cout<<endl;
	}
}

/*
FUNCTION: saveFile
PURPOSE: to save the sorted data in a text file
INPUT: A vector of integers
OUTPUT: None.
 */
void saveFile(vector<int> &toSort, string Filename, string method,
							 int num_elem)
{
	int Alg = FindMethodToSolve(method);
        string SortAlg = convertTostring(Alg);
        string items = convertTostring(num_elem);
	string saveFileName =Filename+"_"+SortAlg+"_"+items+"_sorted.txt"; 
        unsigned int size = toSort.size();
	ofstream file;
	file.open(saveFileName);
	for(unsigned int i = 0; i < size; i++)
	{
		file<<toSort[i];
		file<<endl;
	}
	file<<endl;
	file.close();
}

/*
FUNCTION: convertTostring
PURPOSE: To take an integer and convert it to a string
INPUT: an int
OUTPUT: a string
*/
string convertTostring(int num)
{
        string result;
        ostringstream convert;
        convert<<num;
        result = convert.str();
        return result;
}
/*
FUNCTION: FindMethodToSolve
PURPOSE: to determine which sorting algorithm we used in order to make a
filename.
INPUT: a string
OUTPUT: an int
*/
int FindMethodToSolve(string method)
{
        int alg;
        if(method == "-s1")
        {
                alg = 1;
        }
        if(method == "-s2")
        {
                alg = 2;
        }
        if(method == "-s3")
        {
                alg = 3;
        }
        return alg;
}

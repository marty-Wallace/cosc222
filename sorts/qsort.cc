#include <iostream> 
#include <stdio.h>

using namespace std;

/*
	Utility method to do an in place swap of two numbers in an array
*/
void swap(int v[], int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*
	Basic Quicksort method
	param v, an array of integers to sort 
	param left, the leftmost spot in the array we are concerned with sorting on this recurrence. 
	param right, the rightmost spot in the array we are concerned with sorting on this recurrence
	on the initial call to qsort left should be 0 and right should be the length of the [] - 1
*/
void qsort(int v[], int left, int right) {
	int first = left;
	// let first get the value of left

	int last = right;
	// let last get the value of right

	int pivot = v[(left+right)/2];
	//let pivot be the ~the middle element of the array 

	while(first <= last) {

		while(v[first] < pivot) {
			first++;
		}

		while(v[last] > pivot) {
			last--;
		}

		if(first <= last) {
			swap(v, first, last);
			first++;
			last--;
		}

	}


	if(left < last) 
		qsort(v, left, last);

	if(first < right)
		qsort(v, first, right);

}

/*
	utility method for printing out an array 
	param nums, int[] to print out	
	param l, length of int [] to print out 
*/
void printArr(int nums[], int l) {
	for(int i = 0; i < l; i++) {
		cout << nums[i] << " " ;
	}
	cout << endl;
	cout << endl;
}

/*
	main funtion, create an array and sort it. 
*/
int main() {
	int x = 100000;
	int nums[x];
	for(int i = 0; i < x; i++) {
		nums[i] = x-i;
	}
	//printArr(nums, x);
	qsort(nums, 0, x-1);
	//printArr(nums, x);

	return 0;
}

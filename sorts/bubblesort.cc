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
	Loop through array comparing side by side elements
	Each time the ith element is greater than the i+1th element
	swap them and start iterating through the array from 0 again
*/
void bubblesort(int v[], int l) {
	for(int i = 0; i < l - 1; i++) {
		if(v[i] > v[i+1]){
			swap(v, i, i+1);	
			i = -1; //will increment and become 0 again on next iteration of loop
		}
	}
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
	int x = 10000;
	int nums[x];
	for(int i = 0; i < x; i++) {
		nums[i] = x-i;
	}
	printArr(nums, x);
	bubblesort(nums, x);
	printArr(nums, x);

	return 0;
}

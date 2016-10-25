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

void sort(int[] v, int l) {
	//do stuff
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
	int x = 1000;
	int nums[x];
	for(int i = 0; i < x; i++) {
		nums[i] = x-i;
	}
	printArr(nums, x);
	sort(nums, x);
	printArr(nums, x);

	return 0;
}

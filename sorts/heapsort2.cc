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

void heapify(int v[], int l, int s) {
	for(int i  = s; i >= 0; i--) {
		int parent = i;
		int left = parent * 2 + 1;
		int right = left + 1;
		while(left < l) {
			if(right < l){
				if(v[left] < v[right] && v[right] > v[parent]) {
					swap(v, parent, right);
					parent = right;
				}else if(v[left] > v[right] && v[left] > v[parent]){
					swap(v, parent, left);
					parent = left;
				}else{
					parent = l;
				}
			}else if(v[left] > v[parent]){
				swap(v, left, parent);
				parent = left;
			}else{
				parent = l;
			}
			left = parent * 2 + 1;
			right = left + 1;
		}
	}
}

void sort(int v[], int l) {
	heapify(v, l, (l-1)/2);
	swap(v, 0, --l);
	while(l > 0) {
		heapify(v, l, 0);
		swap(v, 0, --l);
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
	int x = 100000;
	int nums[x];
	for(int i = 0; i < x; i++) {
		nums[i] = x-i;
	}
	printArr(nums, x);
	sort(nums, x);
	printArr(nums, x);

	return 0;
}

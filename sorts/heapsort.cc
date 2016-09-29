#include <iostream> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*
	Utility method to do an in place swap of two numbers in an array
*/
void swap(int v[], int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

//starting at s we will check to see either children of s (if they are in the array)
// are greater than the value at s. if they are then we swap s and it's greatest child
//then we will need to "walk" the value down the tree until it is greater than 
// both of it's children, or it reaches the bottom of the tree
void heapify(int v[], int l, int s) {
	// for original heapification this will iterate over all parent nodes
	// creating local heaps until eventually reaching the root node
	for(int i  = s; i >= 0; i--) {
		//set the parent and children node indexes for this iteration
		int parent = i; 
		int left = parent * 2 + 1; 
		int right = left + 1;
		//while the index of the left child is less than the length of the array 
		//we will continue to "walk down" the tree
		while(left < l) {
			//check the case that there is a left child but not a right child
			//then check to see if value in right is > left 
			//if right is greater than left and parent then swap them 
			if(right < l && v[left] < v[right] && v[right] > v[parent]) {
				swap(v, parent, right);
				parent = right;
			}
			//either no right child or right child is less than left child
			// check if left child is greater
			// if it is then swap with parent
			else if(v[left] > v[parent]){
				swap(v, left, parent);
				parent = left;
			}
			//left child is smaller, and their is no right child
			// we have a local heap
			else{
				parent = l;
			}
			//set new left and right values for the new parent
			left = parent * 2 + 1;
			right = left + 1;
		}
	}
}

/*
	Heapify the array from the bottom then 
	continue swapping the root node out for the bottom node
	reducing the length by one each time until the entire array is sorted
*/
void sort(int v[], int l) {
	//heapify for the first time starting from the parent of the bottom node
	heapify(v, l, (l-1)/2);
	//now that we are heapified we can swap out the root node for the bottom node
	//reduce the length by one and continue on 
	//each  time we swap out the root node we must reheapify starting from the root node. 
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
	srand (time(NULL));    
	int x = 100;
	int nums[x];
	for(int i = 0; i < x; i++) {
		nums[i] = x-i;
	}
	printArr(nums, x);
	sort(nums, x);
	printArr(nums, x);

	return 0;
}

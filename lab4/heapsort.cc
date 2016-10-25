/*
	course: COSC222
	author: Martin Wallace 
	student_id: 300189833
	date: 25/10/2016
	
	Assisment: Translate an old turbo pascal heapsort into a
	C++ heapsort and analyze the running time of the algorithm

	Analysis is above each of the methods

*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std; 

//Moves a single element down into it's spot in the heap in O(log n) time
//Compares the element to both it's children and swaps it with the bigger one
void walkdown(int v[], int j, int n){
	//n is size 
	//j is index of parent within tree
	//exchange parent with > child until parent in place 
	int l = j;
	int k = 2*l + 1;
	bool foundspot = false;
	int ref = v[l];
	while(k < n && !foundspot){
		if(k < n-1){
			if(v[k+1] > v[k]){
				++k; 
			}		
		}
		if(v[k] > ref) {
			v[l] = v[k];
			l = k; 
			k = (2 * l)+1;
		}else{ //appropriate spot has been found
			foundspot = true;
		}
	}
	v[l] = ref;
}

//swap two elements in an array 
void swap(int v[], int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

//print out the array to test the sorting 
void printArr(int nums[], int l) {
    for(int i = 0; i < l; i++) {
        cout << nums[i] << " " ;
    }   
	cout << endl << endl;
}

//heapifies the array by calling walkdown n/2 times
//which results in a complexity of O(n/2 * log n) to 
//turn the array into a heap. 
//once the array is a heap, we can sort it by removing
//the root element of the heap by swapping it with the 
//last node in the heap and removing it from consideration
//then walking down the new root node so we have a heap again
//this process also occurs n times giving us a complexity of
// O(n * log n) with a total complextity of both operations 
// being 1.5 * (n * log n) or more simply O(n * log)
void heapsort(int v[], int n){
	int y = n/2 - 1; //set y to parent of last node
	while(y >= 0){
		walkdown(v, y-- , n);
	}
	y = n; 
	while(y > 0) {
		swap(v, 0, y-1);
		walkdown(v, 0, --y);
	}
}

  

//make an array print it, call heapsort, then print it again.
int main() {
	int size = 100;
	int v[size];
	srand(time(NULL)); //initialize random seed on random function 
	for(int i = 0; i < size; i++){
		v[i] = rand() % ((2 * size)+1); //initialize array with numbers between 0-99
	}
	printArr(v, size); //print pre-sorted array 
	heapsort(v, size);
	printArr(v, size);
	return 0;
}

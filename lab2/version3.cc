/*
	course: COSC222
	author: Martin Wallace
	student_id: 300189833
	date: 21/09/2016
	
	Third attempt at solving the distinct student id problem with space constraint lifted.
	Student ids are always 9 digits
	Student ids are stored in file "stu_id/students.txt"
	Constraint: Must be more time efficient than O(N*N)
	Big O of solution: O(n)
	Approach: Given that all student numbers are unique we know that if there are more than 10 numbers in a set that the first digit can not be unique for all of the numbers so we do not need to check that digit. The same rule applies for each other power of ten. Knowing this we can now iterate through the set of numbers checking the next digit until we find a duplicate. Once we have found a duplicate we can immediately rule out that digit and can move onto the next digit. 
	
*/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int power(int x, int y) {
	int acc = 1;
	for(int i = 0; i < y; i++ ){
		acc *= x;
	}
	return acc;
}

int solve (vector<int> *x) {
	int size = x->size();
	int counter = 1;
	while(size > 10){
		counter++;
		size /= 10;
	}
	int solved = 0;
	int pow, index;
	while(!solved) {
		pow = power(10, counter); //set the power of 10 to use for modulo 
		solved = 1; //set solved = 1 so if we make it through the for loop without finding a duplicate then we can leave the loop 
		int bucket[pow];
		// reset bucket to contain 0s 
		for(int i = 0; i < pow; i++) {
			bucket[i] = 0;
		}
		for(int i = 0; i < x->size(); i++) {
			index = x->at(i) % pow;
			if(bucket[index]++ != 0) {
				solved = 0;
				counter++;
				break;
			}
		}
	}
	return counter;
}


/*
	main function
	opens file "students.txt"
	reads student ids into a vector
	
*/
int main() {
	vector<int>  ids;
	int input, max;
	ifstream myfile("stu_id/students.txt");
	if(myfile.is_open()) { // open file 
		while(myfile >> input ) { //read student id's into vector
			//cout << input << "\n";
			ids.push_back(input);
		}
	}else{
		cout << "Unable to open file\n";
		return 0;
	}
	max = solve(&ids); // find the number of digits required
	if(max < 10)  // print digits
		printf("%d digits required for unique ids\n", max);
	else // There are duplicate numbers 
		cout << "Duplicate numbers in list\n";
}


/*
	course: COSC222
	author: Martin Wallace
	student_id: 300189833
	date: 21/09/2016
	
	First attempt at solving the distinct student id problem.
	Student ids are always 9 digits
	Student ids are stored in file "stu_id/students.txt"
	Constraint: May only use N space 
	Big O of solution: O(n*n)
	Approach: Read ids into a vector then double loop over them comparing each number and keeping tack of the highest number of digits required for uniqueness
	
*/

#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int max(int a, int b) {
	if(a > b) 
		return a;
	return b;
}

int get_diff(int a, int b) {
	int acc = 1; 
	if(a == b){
		return 10;
	}
	while(a % 10 == b % 10){
		acc++;
		a /= 10;
		b /= 10;
	}
	return acc;
}

int solve(vector<int> *nums) {
	int longest = 0;
	int current = 0;
	for(int i = 0; i < nums->size(); i++) {
		for(int j = i; j < nums->size(); j++) {
			if(i == j) continue;
			longest = max(get_diff(nums->at(i), nums->at(j)), longest);
		}
	}
	return longest;
}

/*
	main function
	opens file "students.txt"
	reads student ids into a vector
	Feeds vector into solve function 
*/
int main() {
	vector<int> ids;
	int input, max;
	ifstream myfile("stu_id/students.txt");
	if(myfile.is_open()) { // open file 
		while(myfile >> input ) { //read student id's into vector
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


/*                                                                                                                                                                                     
    course: COSC222
    author: Martin Wallace
    student_id: 300189833
    date: 21/09/2016
    
    2nd attempt at solving the student id problem with no space constraint.
    Student ids are always 9 digits
    Student ids are stored in file "stu_id/students.txt"
    Constraint: Must be more time efficient than O(N*N)
    Big O of solution: O(n * log10(n))
    Approach: Read numbers into a vector then create a vector containing 10
	vector<int>, split digits into vectors 0-9 based on their right-most 
	digit, then recurse upon each of the 10 vectors splitting them up until
	no vector has a size greater than 1. In each branch of the recursion
	keep track of the furthest depth reached. The largest depth is the 
	number of digits required for all numbers to be unique. 

    
*/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
    initialize a vector of vector<int> of size 10 and return it
    
*/
vector<vector<int> > get_struct() {
    vector<vector<int> > x;
    for(int i = 0; i < 10; i++) {
        vector<int> y;
        x.push_back(y);
    }   
    return x;
}

/*
    recursive function to iterate through vector<int> and split up numbers into 
	their corresponding 0-9 vector in a vector<vector<int> > then for each of 
	the 10 vector<int> it recursively solves each. Returns the highest depth 
	seen by the function as the number of digits required for unique ids
*/
int solve (vector<int> x, int depth) {
    if(depth == 10) {  
	//since student ids can only be 9 digits we have gone too far! 
       return depth;
    }   
    if(x.size() < 2) { 
		//if there are less than two elements in this vector then this
		// number is unique at this depth so return it
        return depth;
    }   
    vector<vector<int> > y = get_struct(); //get a vector<vector<int> > 
    for(int i = 0; i < x.size(); i++) {
        if( x.at(i) != 0)  
            y.at(x.at(i) % 10).push_back(x.at(i) / 10); 
			//put the number / 10 into its corresponding vector 
			//(e.g 19 would do into vector 9 10 into vector 0
    }   
    int max = 0; //use max to record highest depth 
    for(int i = 0; i < y.size(); i++ ) { //iterate through each vector
        int temp = solve(y.at(i), depth + 1); //find the max depth
        if(temp > max) 
            max = temp;
    }   
    return max; //return max depth
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
            ids.push_back(input);
        }
    }else{
        cout << "Unable to open file\n";
        return 0;
    }   
    max = solve(ids, 0); // find the number of digits required
    if(max < 10)  // print digits
        printf("%d digits required for unique ids\n", max);
    else // There are duplicate numbers 
        cout << "Duplicate numbers in list\n";
}

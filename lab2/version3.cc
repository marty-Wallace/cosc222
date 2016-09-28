/*                                                                                                                                                                                     
    course: COSC222
    author: Martin Wallace
    student_id: 300189833
    date: 21/09/2016
    
    3rd attempt at solving the student id problem with no space constraint.
    Student ids are always 9 digits
    Student ids are stored in file "stu_id/students.txt"
    Constraint: Must be more time efficient than O(N*N)
    Big O of solution: O(n)
    Approach: Given that all student numbers are unique we know that if 
	there are more than 10 numbers in a set, then the first digit can 
	not be unique for all of the numbers so we do not need to check 
	that digit. The same rule applies for each other power of ten. 
	Knowing this we can now iterate through the set of numbers checking 
	the next digit until we find a duplicate. Once we have found a 
	duplicate we can immediately rule out that digit being unique for 
	all numbers and can move onto the next digit. Continuing forwards this 
	way, as soon as we are able to make a full pass through the numbers 
	we know that we have found the number of digits required for uniqueness. 
	This approach means that in it's worst possible form it will loop over 
	the student numbers 9 times. The trade-off is that the for each digit 
	required for uniqueness 'x' the program requires 10^x space to store 
	the numbers. This means with student numbers of length 9 the space 
	required if all 9 digits were required for uniqueness would be 
	1,000,000,000.
*/

#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
	returns x to the power of y 
*/
int power(int x, int y) {
    int acc = 1;
    for(int i = 0; i < y; i++ ){
        acc *= x;
    }   
    return acc;
}

/*
	finds the number of digits required for unique ids in O(n) time
*/ 
int solve (vector<int> *x) {
    int size = x->size();
    int counter = 1;

	// for each division of 10 of the size of the array
	// we know we do not need to check another digit
    while(size > 10){
        counter++;
        size /= 10; 
    }   
    int solved = 0; //will let us escape once we are done
    int pow, index;

    while(!solved) {
		if(counter == 10) 
			break;

        solved = 1; 
        pow = power(10, counter); //set the power of 10 to use for modulo 
        vector<bool> bucket(pow);
        // reset bucket to contain 0s 
        for(int i = 0; i < x->size(); i++) { //loop through each element 
            index = x->at(i) % pow; //get rightmost of current number
            if(bucket[index]) { //if seen already digit cant be unique, move on 
                solved = 0;
                counter++;
                break;
            }
            bucket[index] = !bucket[index]; //set the bucket as seen 
        }
    }   
    return counter; //return the counter
}


/*
    main function
    opens file "students.txt"
    reads student ids into a vector
	calls solve and prints out the output 
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


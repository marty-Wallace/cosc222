/*
	Program to randomly generate student id's with a given amount of 
	possibly unique digits. 
	Generates a random seed then based on the number of digits that 
	are supposed to be random , d, it generates random-ish numbers 
	and modulo's them by 10^d. 
	Outputs numbers to file "stu_id/students.txt"
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int getLength(int n) {
	if(n == 0)
		return 0;
	return 1 + getLength(n/10);
}
		
int main(int argc, char *argv[] ) {
	srand (time(NULL));
	//initialize random seed
	int n = 0; // number of ids to gen
	int d = 0; // number of digits from the right to gen randomly 
	for(int i = 0; i < argc; i++ ) {
		if(strcmp(argv[i], "-n") == 0 && i < argc-1){
			n = atoi(argv[i+1]);
		}
		if(strcmp(argv[i], "-d") == 0 && i < argc-1){
			d = atoi(argv[i+1]);
		}
	}
	srand(time(NULL));	
	if(!n){
		printf("How many student numbers would you like to generate?\n");
		scanf("%d", &n);
	}
	if(!d){
		printf("How many of the right digits would you like to be randomly generated?\n");
		scanf("%d", &d);
	}
	ofstream file;
	file.open("stu_id/students.txt");
	for(int i = 0; i < n; i++) {
		int prefix = 300189833  / (int)pow(10, d);	

		//since rand() only produces numbers up to 2^15
		//we will bitshift the first random number 15 bits then add it to another number
		// this way we have a 30 bit 'random' integer
		int append = ((rand() << 15) + rand()) % (int)pow(10, d);

		file << prefix ;
		int length = getLength(append);
		if(d != 1) {
			for(int i = length; i < d; i++ ) {
				file << 0;
			}
		}
		file << append << "\n";
	}
	file.close();
}

//Sarah Foss 300253056
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

int getLeastLength(string filename){
  ios::sync_with_stdio(false);

  string line;
  vector<string> listOfInput;
  int counter = 0;

  /*read file into vector*/
  ifstream file(filename.c_str());
  if(file.is_open()){
    while(getline(file,line)){
    listOfInput.push_back(line);
    counter++;
    //cout << line << endl;
      }
    file.close();
  }else{
    cout << "unable to open file" << endl;
    return 1;
  }

  /*get the length of the numbers*/
  int totalLength = listOfInput.front().length();
  // cout << totalLength << endl;
  // cout << counter << endl;

  int size = 10;
  int multi = 10;
  int digitLength = 1;
  bool passed = true;

  /*run a loop that creates an array
  each iteration that is the size
  of the possible numbers in that
  digitlength*/

  while(passed){
    int num[size];
   std::memset(num, 0, sizeof(num));

    for(int i = 0; i < counter; i++){
      string input = listOfInput.at(i);

      /*change the ending digits (of length
    digitLength) into an integer*/
      int c = atoi(input.substr(input.length()-digitLength).c_str());
      if(num[c] == 0){
    /*if the element at the ending digit's position
      in the array equals 0, increment the element*/
    num[c]++;
      }else{
    /*other the digit is not unique and the for
      loop must be broken*/
    passed = false;
    break;
      }
    }
    if(passed){
      /*if the digitLength passed the for loop
    without breaking that is the shortest
    unique ending ending*/
      cout << digitLength << endl;
      break;
    }else{
      /*multiply the test size by 10, increment the
    digit length and reset the condition of the
    while loop*/
      size = size * multi;
      digitLength++;
      passed = true;
    }
  }
}


int main(){
  ios::sync_with_stdio(false);
  string filename = "stu_id/students.txt";
  getLeastLength(filename);
  return 0;
}


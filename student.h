#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

public:
  // Functions for Student class
  Student();
    //name
  char* getFirstName();
  char* getLastName();
    
    //ID
  int getID();
    void setID(int tempID);

    //GPA
    float getGPA();
  void setGPA(float tempGPA);
  
    void print();  // print function

private:
//Initialzing variables 
  char firstName[81];
  char lastName[81];
  int studentID;
  float GPA;
};

#endif

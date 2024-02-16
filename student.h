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
    void setFirstName(char tempFirst[]);
    void setLastName(char tempLast[]);
    
    //ID
  int getID();
    void setID(int tempID);

    //GPA
    float getGPA();
  void setGPA(float tempGPA);
  
    void print();  // print function

private:
//Initialzing variables 
    char tempFirst[81];
    char tempLast[81];
  char firstName[81];
  char lastName[81];
  int studentID;
  float GPA;
};

#endif

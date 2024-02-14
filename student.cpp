#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student() {
  // Each student has these variables
  strcpy(firstName, "");
  strcpy(lastName, "");
  studentID = 0;
  GPA = 0.0;
}

//Name
char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}


//GPA
float Student::getGPA() {
  return GPA;
}

void Student::setGPA(float tempGPA) {
  GPA = tempGPA;
}


//ID
void Student::setID(int tempID) {
  studentID = tempID;
}

int Student::getID() {
  return studentID;
}

void Student::print() {
  cout << "Student: " << firstName << " " << lastName << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "GPA: " << GPA << endl;
    cout << endl;
}

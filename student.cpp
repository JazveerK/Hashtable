#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
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

void Student::setFirstName(char tempFirst[]) {
    strncpy(firstName, tempFirst, sizeof(firstName) - 1);
    firstName[sizeof(firstName) - 1] = '\0';
}

void Student::setLastName(char tempLast[]) {
    strncpy(lastName, tempLast, sizeof(lastName) - 1);
    lastName[sizeof(lastName) - 1] = '\0';
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
    cout << "GPA: " << GPA << fixed << setprecision(2) << endl;
    cout << endl;
}

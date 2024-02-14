#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"

using namespace std;

class Node {
public:
  // constructor (and the student assigned to the node)
  Node(Student* newStudent);
    //Node(); Each node should contain a student


  // destructor
  ~Node();

  // get the next node in the list
  Node* getNext();

  // set the next node in the list
  void setNext(Node* n);
    
    Student* getStudent();
    
    //THESE FUNCTIONS ONLY WORK FOR LINKLIST PART ONE

    //void setValue(int newvalue);
    //int getValue();
    
    
private:
  // Variables
  Node* next;
  Student* s;
};
#endif

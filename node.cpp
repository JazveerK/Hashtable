#include <iostream>
#include "node.h"

using namespace std;

// Constructor
Node::Node(Student* newStudent) {
  s = newStudent;
  next = NULL;
}

// Destructor
Node::~Node() {
  delete s;
  next = NULL;
}

// Getters
Node* Node::getNext() {
  return next;
}

// Setters
void Node::setNext(Node* n) {
  next = n;
}

Student* Node::getStudent() {
  return s;
}


/*
 This works for Linked List part 1, but is not really helpful for link list part 2
 
 void Node::setValue(int newvalue) {
    student.setValue(newvalue);
 }
 
 int Node::getValue() {
    return student.getValue();
 }
 */


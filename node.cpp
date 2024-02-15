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



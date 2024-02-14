// Jazveer Kaler
//  10/22/2023
//  Studentlist
//  Description: This program will display a menu of options to the user. The user will be able to add a student, delete it, and print out all students. This is accomplished through a Hash Table.
//

#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include "node.h"
#include "student.h"

using namespace std;

// function prototypes
void add();
void print();
void del();
void rand();
void hash();
void rehash();

int main() {
  bool running = true;
  char command[15];
  Node* head = NULL;
    
    Node** hash = new Node* [100];
    for (int i = 0; i < 100; i++) {
        hash[i] = NULL;
    }
    
    int size = 100;

    cout << "WELCOME TO STUDENT LIST AGAIN" << endl;
    cout << "Hash Table" << endl;

  // From my student list code
  while (running == true) { //while loop running the program

    // takes in commands
    cout << "Type in a command: ADD, PRINT, DELETE, RANDOM, or QUIT" << endl;
    cin.get(command, 16);
    cin.ignore(16, '\n');

    // ADD
    if (strcmp(command, "ADD") == 0) {
        Student* inputStudent = new Student();
         //Takes in information
         cout << "First Name: " << endl;
         char input[20];
         cin.get(input, 20);
         cin.ignore(80, '\n');
         strcpy(inputStudent->getFirstName(), input);
         
         cout << "Last Name: " << endl;
         cin.get(input, 20);
         cin.ignore(80, '\n');
         strcpy(inputStudent->getLastName(), input);
         
         cout << "Student ID: " << endl;
         int int1;
         cin >> int1;
         cin.ignore(80, '\n');
         inputStudent->setID(int1);
         
         cout << "Student GPA: " << endl;
         float float1;
         cin >> float1;
         cin.ignore(80, '\n');
         inputStudent->setGPA(float1);

         Node* inputNode = new Node(inputStudent);
         
         add();
    }

    // PRINT
    else if (strcmp(command, "PRINT") == 0) {
        cout << "Printing all students: " << endl;
        print();
    }

    // DELETE
    else if (strcmp(command, "DELETE") == 0) {
        cout << "What ID would you like to delete?" << endl;

        int deleteID;
        cin >> deleteID;
        cin.get();
        int index = deleteID % size;
        

        remove(hash[index], hash[index], hash[index], deleteID);
    }
      
    // AVERAGE
    else if (strcmp(command, "AVERAGE") == 0) {
        float sumGPA = 0;
        int totalNodes;
        avg();
    }

    // QUIT
    else if (strcmp(command, "QUIT") == 0) {
      cout << "Program ended." << endl;
      running = false;
    }
  }
  return 0;
}

void add() {
}

void del(Node* &head, Node* current, Node* prev, int deleteID) {

    if(head == NULL){
      return;
    }
    
    else{
     
      if(current->getStudent()->getId() == deleteID){
        if(current == head){
          Node* tempNode = current->getNext();
          delete head;
          head = tempNode;
        }
        else{
          prev->setNext(current->getNext());
          delete current;
        }
      }

      else{
        if(current->getNext()!= NULL){
          remove(head, current->getNext(), current, deleteID);
        }
        else{
          return;
        }
        return;
      }
    }
  }
}

void avg() {

}

// print
void print() {

}

void hash(int size, Node** &hash, bool &rehash) {
    rehash = false;
    Node** newHash = new Node*[size*2];
    for (int i = 0; i < size*2: i++) {
        newHash[i] = NULL'
    }
    
    for (int i = 0; i < size; i++) {
        Node* temp = hash[i];
        Node* tempTwo = hash[i];
        Node* tempThree = hash[i];
        Node* tempFour = hash[i];
    }
    
    tempTwo = temp -> getNext();
    tempThree = tempTwo -> getNext();
    tempFour = tempThree -> getNext();
    
    
   
    size = size * 2;
    delete[] hash;
    hash = newHash;
    return;
}

void rehash(Node** &hash,) {
    int count;
    if (count == 3) {
        rehash = true;
    }
    
    if rehas
}

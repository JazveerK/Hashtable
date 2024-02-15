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
    bool rehashNeeded = false;
    
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

         
         add(inputStudent, size, hash);
        
        // Check if rehashing is needed
        hash(size, hash, rehashNeeded);
        if (rehashNeeded) {
            rehash(hash, size);
            rehashNeeded = false;
        }
    }

    // PRINT
    else if (strcmp(command, "PRINT") == 0) {
        cout << "Printing all students: " << endl;
        print(hash, size);
    }

    // DELETE
    else if (strcmp(command, "DELETE") == 0) {
        cout << "What ID would you like to delete?" << endl;

        int deleteID;
        cin >> deleteID;
        cin.get();
        
        del(hash, size, deleteID);
        
        // Check if rehashing is needed
        hash(size, hash, rehashNeeded);
        if (rehashNeeded) {
            rehash(hash, size);
            rehashNeeded = false;
        }
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

void add(Student* newStudent, int &size, Node** &hash) {
    
       int hashValue = newStudent->getID() % size;
       Node* newNode = new Node(newStudent);

       // chaining
       if (hash[hashValue] == nullptr) {
           hash[hashValue] = newNode;
       } 
       
       else {
           newNode->setNext(hash[hashValue]);
           hash[hashValue] = newNode;
       }

       cout << "Student added successfully." << endl;
   }
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

// print
void print() {
    for(int i = 0; i < size; i++){
        
      if(hash[i] != NULL) {
        hash[i]->getStudent()->print();

        if(hash[i]->getNext() != NULL) {
            hash[i]->getNext()->getStudent()->print();;
            
          if(hash[i]->getNext()->getNext()!=NULL) {
              hash[i]->getNext()->getNext()->getStudent()->print();;
          }
        }
      }
    }
    return;
}

void hash(int size, Node** &hash, bool &rehashNeeded) {
    int collisionThreshold = 3;
    int totalCollisions = 0;

    // Calculate total collisions
    for (int i = 0; i < size; ++i) {
        if (hash[i] != nullptr) {
            Node* current = hash[i];
            while (current->getNext() != nullptr) {
                totalCollisions++;
                current = current->getNext();
            }
        }
    }

    // Check if rehashing is needed
    if (totalCollisions > collisionThreshold * size) {
        rehashNeeded = true;
    }
}


void rehash(Node** &hash, int &size) {
    int newSize = size * 2;
    Node** newHash = new Node* [newSize];

    // new hash table
    for (int i = 0; i < newSize; ++i) {
        newHash[i] = nullptr;
    }

    // Rehash
    for (int i = 0; i < size; ++i) {
        
        if (hash[i] != NULL) {
            Node* current = hash[i];
            
            while (current != NULL) {
                Node* next = current->getNext();
                int hashValue = current->getStudent()->getID() % newSize;

                if (newHash[hashValue] == NULL) {
                    newHash[hashValue] = current;
                    current->setNext(NULL);
                } 
                
                else {
                    current->setNext(newHash[hashValue]);
                    newHash[hashValue] = current;
                }

                current = next;
            }
        }
    }

    //updating variables
    delete[] hash;
    hash = newHash;
    size = newSize;

    cout << "Hash table rehashed. New size: " << newSize << endl;
}

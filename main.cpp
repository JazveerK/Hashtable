// Jazveer Kaler
// 10/22/2023
// Studentlist
// Description: This program will display a menu of options to the user.
// The user will be able to add a student, delete it, and print out all students.
// This is accomplished through a Hash Table.

#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include "node.h"
#include "student.h"

using namespace std;

// Function prototypes
void add(Student* newStudent, int &size, Node** &hash);
void print(Node** &hash, int &size);
void del(Node** &hash, int &size, int deleteID);
void hashFunction(int size, Node** &hash, bool &rehashNeeded);
void rehash(Node** &hash, int &size);

int main() {
    bool running = true;
    char command[15];
    Node* head = nullptr; // Initializing head pointer to nullptr
    
    Node** hash = new Node* [100];
    for (int i = 0; i < 100; i++) {
        hash[i] = nullptr;
    }
    
    int size = 100;
    bool rehashNeeded = false; // Initializing rehashNeeded variable
    
    cout << "WELCOME TO STUDENT LIST AGAIN" << endl;
    cout << "Hash Table" << endl;

    // Main program loop
    while (running) { 

        // Takes in commands
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
            
            // Check if rehashing is needed after adding or deleting
            hashFunction(size, hash, rehashNeeded);
            
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
            
            // Check if rehashing is needed after adding or deleting
            hashFunction(size, hash, rehashNeeded);
            if (rehashNeeded) {
                rehash(hash, size);
                rehashNeeded = false;
            }
        }
        
        else if (strcmp(command, "RANDOM") == 0) {
            
        }



        // QUIT
        else if (strcmp(command, "QUIT") == 0) {
            cout << "Program ended." << endl;
            running = false;
        }
    }

    // Freeing memory allocated for hash table
    for (int i = 0; i < size; i++) {
        delete hash[i];
    }
    delete[] hash;

    return 0;
}

void add(Student* newStudent, int &size, Node** &hash) {
    int hashValue = newStudent->getID() % size;
    Node* newNode = new Node(newStudent);

    // Chaining
    if (hash[hashValue] == nullptr) {
        hash[hashValue] = newNode;
    } else {
        newNode->setNext(hash[hashValue]);
        hash[hashValue] = newNode;
    }

    cout << "Student added successfully." << endl;
}

void del(Node** &hash, int &size, int deleteID) {
    int hashValue = deleteID % size;
    Node* current = hash[hashValue];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->getStudent()->getID() == deleteID) {
            if (prev == nullptr) {
                hash[hashValue] = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }
            delete current;
            cout << "Student deleted successfully." << endl;
            return;
        }
        prev = current;
        current = current->getNext();
    }

    cout << "Student with ID " << deleteID << " not found." << endl;
}

// Print
void print(Node** &hash, int &size) {
    for (int i = 0; i < size; i++) {
        Node* current = hash[i];
        while (current != nullptr) {
            current->getStudent()->print();
            current = current->getNext();
        }
    }
}


void hashFunction(int size, Node** &hash, bool &rehashNeeded) {
    int collisionThreshold = 3;
    int totalCollisions = 0;

    // Calculate total collisions
    for (int i = 0; i < size; ++i) {
        Node* current = hash[i];
        while (current != nullptr) {
            totalCollisions++;
            cout << "total collisions: " << totalCollisions << endl;
            current = current->getNext();
        }
    }

    // Check if rehashing is needed
    if (totalCollisions > collisionThreshold) {
        rehashNeeded = true;
    }
}

void rehash(Node** &hash, int &size) {
    int newSize = size * 2;
    Node** newHash = new Node*[newSize];
    
    // New hash table
    for (int i = 0; i < newSize; ++i) {
        newHash[i] = nullptr;
    }
    
    // Rehash
    for (int i = 0; i < size; ++i) {
        Node* current = hash[i];
        while (current != nullptr) {
            Node* next = current->getNext();
            int hashValue = current->getStudent()->getID() % newSize;
            
            if (newHash[hashValue] == nullptr) {
                newHash[hashValue] = current;
                current->setNext(nullptr);
            } else {
                current->setNext(newHash[hashValue]);
                newHash[hashValue] = current;
            }
            current = next;
        }
    }
       
    // Update variables
    delete[] hash;
    hash = newHash;
    size = newSize;

    cout << "Hash table rehashed. New size: " << newSize << endl;
}

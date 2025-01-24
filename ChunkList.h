//
// Created by Varick Erickson 2/3/2021.
//

#ifndef CHUNKLIST_H
#define CHUNKLIST_H

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 8;

// These error classes are done. No modifications are required.
// See ChunkList_driver.cpp for an example of how they are used.
class InvalidArrayLength{
public:
    string Msg() {
        return "Invalid array length used for constructor.";
    }
};

class IndexOutOfBounds {
public:
    string Msg() {
        return "Index is out of bounds";
    }
};

class IteratorOutOfBounds {
public:
    string Msg() {
        return "Iterator is out of bounds.  Nothing left to iterate over.";
    }
};

class EmptyList {
public:
    string Msg() {
        return "List is empty";
    }
};

// Put your pre/post conditions here.

template<class T>
class ChunkList {
public:
    // Constructors
    /*
    * Function: This is the default constructor.
    * Precondition: none
    * Postcondition: Sets the 'head', 'tail' and 'iterNode' to nullptr and 'arrPos', 'listLen' and 'numChunks to 0
    */
    ChunkList();

    /*
    * Function: The function is a constructor that initializes all the private variables
    * Precondition: The parameters are the array and the array length. The variables have to exist within the class.
    * The ResetIterator and Append method need to be working in order to be successfully implemented.
    * Postcondition: Sets the 'head' and 'tail' to nullptr and 'listLen' and 'numChunks to 0
    * Ensures array length is a valid number and appends the values to the array
    */
    ChunkList(T arr[], int arrLen);

    // Deconstructor
    /*
    * Function: The function is a deconstructor
    * Precondition: The variables listLen and numChunks have to exist within the class.
    * Postcondition: Sets the node 'temp' to 'head' and deletes the nodes
    */
    ~ChunkList();

    // Add/remove elements
    /*
    * Function: The function appends values to the chunklist by adding it to the end of the list
    * Precondition: It takes value as a parameter.
    * Postcondition: Successfully appends the value to the end of the list. Doesn't return anything
    */
    void Append(T value);

    /*
    * Function: The function removes a value from the chunklist and deletes the nodes if necessary
    * Precondition: It takes value as a parameter. The variables have to exist within the class (values, len, listLen, numChunks, etc.). The list cannot be empty, else it'll throw an error
    * Postcondition: Successfully removes the first instance of the value while maintaining the order. Deletes the node if it's empty Doesn't return anything
    */
    void Remove(T value);

    // Stuff to find out about the ChunkList

    /*
    * Function: The function is a getter
    * Precondition: The variable has to exist within the class
    * Postcondition: Access and returns the listLen
    */
    int GetLength();

    /*
    * Function: The function determines how much of the chunklist is used
    * Precondition: The variable has to exist within the class. The list cannot be empty. Doesn't take any parameters
    * Postcondition: Calculates the utilization percentage and throws an empty list if empty
    */
    double LoadFactor();

    /*
    * Function: The function determines if a value exists or not in the chunklist
    * Precondition: The list cannot be empty. Takes value as a parameter
    * Postcondition: Returns true if the value exists in the chunklist. Returns false if it doesn't.
    */
    bool Contains(T value);

    // Accessing elements
    /*
    * Function: The function gives the value at an index
    * Precondition: The list cannot be empty and the index cannot be out of bounds. Takes the integer i as a parameter
    * Postcondition: Gives the value at the specified index if it exists. Will throw an error if index is out of bounds or if list is empty
    */
    T GetIndex(int i);

    /*
    * Function: The function resets the iterator
    * Precondition: The variable has to exist within the class. iterNode is set to head and arrPos is set to 0
    * Postcondition: Resets the iterator back to default
    */
    void ResetIterator();

    /*
    * Function: The function returns the current item and gets the next item in the list
    * Precondition: The list cannot be empty and the iterator cannot be out of bounds
    * Postcondition: Returns the current item and points to the next. Will throw an error if list is empty or the iterator is out of bounds
    */
    T GetNextItem();

    /*
    * Function: The function is a boolean that can be called to check if a list is empty
    * Precondition: none
    * Postcondition: Returns true if list is empty and false if it isn't
    */
    bool IsEmpty();
private:

    // Note we did not need to make this a template
    // since this struct is part of a template class.
    struct Node {
        Node* next;
        int len;
        T values[ARRAY_SIZE];
    };

    Node* head;
    Node* tail;

    // iterator
    Node* iterNode;     // What node are were currently on?
    int arrPos;         // Within the node, what element are we looking at?

    int listLen;        // Total elements
    int numChunks;      // Total chunks/nodes
};

#include "ChunkList.cpp"

#endif //CHUNKLIST_H

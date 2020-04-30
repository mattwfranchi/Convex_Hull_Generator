// Matt Franchi // CPSC 2120 // Spring 2020
// Project 2 : Cilli.cpp
// File Description: Implementation of Cilli class

#include "Cilli.h"

using namespace std;

// DEFAULT CONSTRUCTOR
// creates blank Cilli with handle set to nullptr
Cilli::Cilli() : handle(nullptr) {}

// FUNCTION -- insertItem(int v)
// inserts a CNode initialized with v at the current handle
void Cilli::insertItem(int v) {
    // CASE I -- EMPTY CILLI
    if (handle == nullptr) {
        handle = new CNode(v);
        handle->forward = handle->behind = handle;
    }
        // CASE I -- NONEMPTY CILLI
    else {
        handle = new CNode(v, handle->forward, handle);
        handle->forward->behind = handle->behind->forward = handle;
    }

}

// FUNCTION -- dumpForwards()
// prints out the Cilli in clockwise order
void Cilli::dumpForwards() const {
    cout << "Contents of Cilli (Forward Order): " << handle->val;
    for (CNode *cursor = handle->behind; cursor != handle; cursor = cursor->behind) {
        cout << ", " << cursor->val;
    }
    cout << endl;
}

// FUNCTION -- dumpBackwards()
// prints out the Cilli in counter-clockwise order
void Cilli::dumpBackwards() const {
    cout << "Contents of Cilli (Backward Order): " << handle->val;
    for (CNode *cursor = handle->forward; cursor != handle; cursor = cursor->forward) {
        cout << ", " << cursor->val;
    }
    cout << endl;
}

// FUNCTION -- moveHandleForward()
// moves the Cilli's handle pointer one forward
void Cilli::moveHandleForward() {
    handle = handle->forward;
}

// FUNCTION -- moveHandleBack()
// moves the Cilli's handle pointer one backward
void Cilli::moveHandleBack() {
    handle = handle->behind;
}

// FUNCTION -- getValAtHandle()
// returns the value stored in the CNode currently pointed to by handle
int Cilli::getValAtHandle() const {
    return handle->val;
}

// FUNCTION -- deleteItem()
// deletes the current handle, replaces it with the CNode behind handle
void Cilli::deleteItem() {
    CNode *nodeToDelete = handle;
    handle->behind->forward = handle->forward;
    handle->forward->behind = handle->behind;
    handle = handle->behind;
    delete nodeToDelete;
}

// DESTRUCTOR
Cilli::~Cilli() {
    for (CNode *cursor = handle->forward; cursor != handle; cursor = cursor->forward) {
        deleteItem();
    }

    deleteItem();

}

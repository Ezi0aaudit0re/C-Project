/**
 * This file contains the implementation of Array class
 * @author Aman Nagpal
 * @version 2.0
 */

#include <iostream>
#include "Array.h"
#include "Helper.h"
#include <vector>
#include <string.h>

#define DEBUG false

using namespace std;

/**
 * Default Constructor
 * Dynamically create an array of size 5
 */
Array::Array(){
    // if no size given default size of 5
    this->arrayP = new string[this->getSize()];
}

/**
 * Constructor
 * @param len -> THe length of the array
 */
Array::Array(int len){
    this->setSize(len);
    this->arrayP = new string[len];
}

/**
 * Destructor
 */
Array::~Array(){
    delete[] this->arrayP;
    cout << "The program is Quiting thanks for participating" << endl; 
}

// setters
void Array::setSize(int len){
    this->size = len;
}

/**
 * Sets the value of the array at a particular location
 */
void Array::setArray(int loc, string str){
    this->arrayP[loc] = str;

}


// getters
int Array::getSize(){
    return this->size;
}


string* Array::getArrayP(){
    return this->arrayP;
}


/**
 * This method adds to the array 
 * Copies the old array to the new array with an increased size of 1
 * @param size -> refrence to the size 
 * @param toAdd -> The string to add
 * @return pointer to the new array
 */
string* Array::add(int &size, string toAdd){

    int len = this->getSize() + 1;
    string* arr = new string[len];
    // size of old array , pointer to old array, pointer to new array
    Helper::copy(this->getSize(), this->getArrayP(), arr);

    arr[len - 1] = toAdd; // add the new string to the end of the array
    // update the size
    size = len;
    // update the private size variable
    this->setSize(size);

    // delete the old array
    delete[] this->arrayP;
    // assign the new pointer to the array to the old pointer

    // asign space for this->arrayP on heap
    this->arrayP = new string[len];
    // copy to the new array 
    Helper::copy(len, arr, this->arrayP);
    // delete the array created in this method

    delete[] arr;
    return this->arrayP;
}

/**
 * This method checks if a string exists in array
 * if it does then deletes it and updates it
 * @param size -> The size of the arr
 * @param string-> the string to delete
 * @return NULL -> if string is not found
 *         pointer to updated array if found
 */
string* Array::del(int &size, string toDel){

    int loc = Helper::checkExistence(this->getSize(), this->getArrayP(), toDel);
    if(loc != -1){
        // save the new size in len
        int len = this->getSize() - 1;

        // move the string to the end of the array
        string temp = this->arrayP[loc];
        this->arrayP[loc] = this->arrayP[this->getSize() -1];
        this->arrayP[this->getSize() -1] = temp;



        // create a new array of size len
        string* arr = new string[len];

        // now we just pop the last element
        Helper::copy(len, this->getArrayP(), arr);

        size = len;
        this->setSize(size);

        delete[] this->arrayP;

        this->arrayP = new string[len];
        Helper::copy(len, arr, this->arrayP);

        // free memory for array allocated in this method
        delete[] arr;
        return this->arrayP;
    
    }

    cout << "This string is not present in the array" << endl;

    return NULL;
}

/**
 * Loops throug the array provided as parameter 
 *      Add each element to the array using this->add(stribg)
 */
void Array::addArray(string arrayToAdd[], int size, int& capacity){

    arrayToAdd = Helper::getStringArray(size);
    for(int itter=0; itter < size; itter++){
        this->add(capacity, arrayToAdd[itter]);
    }
    delete[] arrayToAdd;

}


void Array::removeArray(string arrayToRemove[], int size, int &capacity ){

    arrayToRemove = Helper::getStringArray(size);
    for(int itter = 0; itter < size; itter++){
        this->del(capacity, arrayToRemove[itter]);
    
    }

    delete[] arrayToRemove;



}








/**
 * We overload the operator << 
 * @param Array -> The object 
 */
void Array::operator<<(Array arr){
    Helper::printArray(arr.getSize(), arr.getArrayP());
}



/**
 * This file consists of helper methods
 * @version 2.0
 * @author Aman Nagpal
 */
#include <iostream>
#include <sstream>
#include <vector>
#include "Helper.h"

using namespace std;


/**
 * This is a helper method that copies from one arr to another
 * @param len length of the existing array 
 * @param old[] the old array 
 * @param *newArr -> pointer to the new array
 */
void Helper::copy(int len, string old[], string* newArr){
    for(int i =0; i < len; i++){
        newArr[i] = old[i]; 
    }
}

/**
 * THis method prints the array provided to it
 * @param len -> THe length of the array
 * @param arr -> the pointer to the array
 */
void Helper::printArray(int len, string* arr){
    for(int i =0; i < len; i++){
        cout << arr[i] << endl;
    }
}

/**
 * This method checks if the string exists in the array
 * @param -> len the length of the array
 * @param -> arr the array
 * @param -> str The string to check
 * @return -> location of string else -1 
 */
int Helper::checkExistence(int len, string arr[], string str){

    for(int i =0; i< len; i++){
        if(arr[i].compare(str) == 0){
            // string is found return true
            return i; 
        } 
    }
    return -1;
}


/**
 * THis method overloads the getStringArray
 * creates an array pointer fills its values and returns it
 * @param size -> The size of the array of new values when options [1, 2]
 * @return  arr
 */
string* Helper::getStringArray(int size){
    string* arr = new string[size];

    for(int itter = 0; itter < size; itter++){
        cout << "Enter string " << itter+1 << ": " ; 
        cin >> arr[itter];
    }


    return arr;


}

/**
 * This methods gets a line from the user and returns an array filled with those values
 * @param size => The size of the array made
 * @param ques => The ques to be asked to the user
 * @return a pointer to strings
 */
string* Helper::getStringArray(int size, string ques){



   
    // ask the user for a question
    cout << ques;


    getchar();
    // declare a string and get a line from the user 
    string line;
    getline(cin, line);

    // declare a vector
    vector<string> vec;

    string word ="";
    // loop throught the line using sstream
    for(int itter = 0, len = line.size(); itter < len; itter++){
        if(isspace(line[itter])){
            // if we reach a space means a new word has started
            // add the previous word to the vector
            vec.push_back(word);
            // reset the str to start storing new word
            word = "";
        }
        else{
            word += line[itter];
        }
    }

    // call the Helper::vecToArray which converts a vector to an array
    return Helper::vecToArray(size, vec);

}

/**
 * This methods converts a vector to an array 
 * @param vec // vector to be converted to array
 * @param size // size of the new array created
 * @return [length of the new array, new array] // array that had a pre-image of a vector
 *      arr[0] = lenght of the new array 
 *      arr[1] = new arr
 */
string* Helper::vecToArray(int size, vector<string> vec){

    string* arr = new string;
    for(int itter=0, len = vec.size(); itter < len; itter++ ){
        // we do the comparison >= size becuase size is the length of the array 
        // if we try to add to the arr[arr.length()] we would get an error
        if(itter >= size){
            break;
        }
        arr[itter] = vec[itter];
    }

    // return a pointer to a new array of strings
    return arr;
}


/**
 * This method gives the user options to choose from 
 * A: Add
 * 1: Add an entire array
 * P: Print the array
 * D: Delete
 * 2: Delete an entire array input in format of a line
 * E: Exit
 */
string Helper::getInput(){

    string str;
    cout << "\n\n MENU ------" << endl;
    cout << "You can add or delete a string to the array" << endl;
    cout << "           A: Add to array "<< endl;
    cout << "           1: Add an entire array to the Existing Array"<< endl;
    cout << "           P: Print the array "<< endl;
    cout << "           D: Delete from array "<< endl;
    cout << "           2: Delete array of elements from the array "<< endl;
    cout << "           E: Exit the program "<< endl;
    cin >> str;
    return str;
}

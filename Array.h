/**
 * This is the header file for the array class
 * @author Aman Nagpal
 * @version 2.0
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array{

    private:
        string *arrayP = NULL; // pointer to the dynamically generated array
        int size = 5; // the size of that array [default = 5]

    public:
        Array(); // default Constructor
        Array(int); // Constructor that takes in the length of the array 
        ~Array(); // Deconstructor
        
        // Getters 
        string* getArrayP();
        int getSize();

        //Setters 
        void setSize(int);
        void setArray(int, string);

        // member methods
        string* add(int&, string);
        string* del(int&, string);

        //overlad operator << 
        void operator<< (Array);
        void addArray(string arrayToAdd[], int size, int& capacity);
        void removeArray(string arrayToRemove[], int size, int &capacity);


};

#endif

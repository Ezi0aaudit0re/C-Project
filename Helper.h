#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <vector>

class Helper{
    
    public:
        // copy from one array to another
        static void copy(int, std::string[], std::string*);
        // print the array provied till the length provided
        static void  printArray(int, std::string*);
        // checks if a string is in an array
        static int checkExistence(int, std::string[], std::string);
        // get the input from the user 
        static std::string getInput();
        // get a string array from the user 
        static std::string* getStringArray(int, std::string ques);
        // this methdo uses arrays
        static std::string* getStringArray(int);
        // covert a vector to a array
        static std::string* vecToArray(int, std::vector<std::string>);
        // clears the value stored in cin 
        static void clearCin();

};



#endif



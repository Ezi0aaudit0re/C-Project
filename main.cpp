/**
 * This file is the main driver of the program
 * @author Aman Nagpal
 * @version 2.0
 */
#include <iostream>
#include "Array.h"
#include "Helper.h"
#define DEBUG false


using namespace std;

int main(int argc, char* argv[]){



    // ask the user for the length of the array 
    // default size of 0 will only be used for debugging
    int size = (DEBUG) ? 3 : 0; 
    if (argc == 2){
        size = atoi(argv[1]);
    }
    else if(!DEBUG){
        cout << "Please enter the size of the array and then press enter" << endl; 
        cin >> size;
    }

    // check if the size has been entered
    if(size == 0 && !DEBUG){
        cout << "Please enter a correct size and rerun the program" << endl; 
        cout << "You can also enter the size as a command line arugment eg: ./a.out <size>" << endl;
        exit(1);
    }

    // initialize the array 
    Array arr(3); 
    // use this for debuging so as not to enter input again and again
    if(DEBUG){
        arr.setArray(0, "Aman");
        arr.setArray(1, "Nagpal");
        arr.setArray(2, "c++");
    }
    else{
    
        for(int i = 0; i < size; i++){
            string str;
            cout << "Please enter string " << (i+1) << ": ";
            cin >> str;
            arr.setArray(i, str);
        }
    
    } // end if-else



   // run a loop till the user wants to exit
   while(true){
       string userIn = Helper::getInput();
       if(userIn.compare("A") == 0){
           // add to the array
           int size;
           string str;
           cout << "Enter the string you want to ADD to the array: ";
           cin >> str;
           arr.add(size, str); 
           Helper::printArray(size, arr.getArrayP());
       
       }
       else if(userIn.compare("D") == 0){
           // Delete from the array
           int size;
           string str;
           cout << "Enter the string you want to DELETE to the array: ";
           cin >> str;
           arr.del(size, str); 
       }
       else if(userIn.compare("E") == 0){
           // exit the program
           // overloaded << operator
           cout << "The final array is: " << endl;
           arr<<arr;
           exit(0);
       }
       else if(userIn.compare("P") == 0){
           cout << "The final array is: " << endl;
           Helper::printArray( arr.getSize(), arr.getArrayP());
       }
       // remove an array from the array of words
       else if(userIn.compare("1") == 0){
           int size = 0;
            cout << "Please Enter the number of words you want to add to the array: ";
            cin >> size;

          if(cin.fail()){
               cout << "You entered an incorrect string" << endl; 
               // clear the value from cin else incorrect value entered is stored in cin and gets passed to get imput method
               Helper::clearCin();
          }
          else{
              // get the capacity of the array
              int capacity = arr.getSize();
              string* addArr = nullptr;
              arr.addArray(addArr, size, capacity);
              cout << "Words stored from the array" << endl;
          }


       }
       else if(userIn.compare("2") == 0){
       
           int size = 0;
           cout << "Please Enter the number of words you want to delete from the array: ";
           cin >> size;
           if(cin.fail()){
                 cout << "You entered an incorrect string" << endl; 
               // clear the value from cin else incorrect value entered is stored in cin and gets passed to get imput method
                 Helper::clearCin();
            }
           else{
               // get the capacity of the array
               int capacity = arr.getSize();
               string* removeArr = nullptr;
               arr.removeArray(removeArr, size, capacity);
               cout << "Words removed from the array" << endl;
           
           }

       
       }
       else{
            cout << "Please choose a correct option" << endl;
       }
   }

}

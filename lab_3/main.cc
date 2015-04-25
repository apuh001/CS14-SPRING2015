//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab3/main.cc
/// @brief Lab 3 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 4/23/2015
/// @SID: 861162817
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include "lab3.h"

using namespace std;

int main()
{
    TwoStackFixed<int>test(4, 1); //4 slots, equally distrib index 0,1 goes to 
                              //stack 1, index 2, 3 goes to stack 2
    cout << "Stack1 is empty? " << test.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test.isFullStack2()<< endl;
   
    
        
    return 0;
}

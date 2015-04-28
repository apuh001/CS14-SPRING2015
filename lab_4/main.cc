//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab4/main.cc
/// @brief Lab 4 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 4/27/2015
/// @SID: 861162817
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#include "lab4.h"
using namespace std;

int main()
{
    cout << "preorder" << endl;
    
    list_preorder(2, 1, 9);
    list_preorder(3, 1, 9);
    
    cout << "postorder" << endl;
    
    list_postorder(2, 1, 9);
    //list_postorder(3, 1, 9);
}
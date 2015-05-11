//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab5/main.cc
/// @brief Lab 5 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 5/4/2015
/// @SID: 861162817
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#include <map>
#include "lab5.h"
using namespace std;

int main()
{
    BST<int> myBST;
    myBST.insert(50);
    myBST.insert(20);
    myBST.insert(60);
    myBST.insert(10);
    myBST.insert(40);
    myBST.insert(70);
    myBST.insert(35);

    //myBST.minCover();
    int strr[100];
    myBST.findSumPath(myBST.root, 80, strr);
    map<int, int> aMap;
    myBST.vertSum(myBST.root, 0, aMap);
    
    return 0;
}
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
#include <stack>
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
   
    test.pushStack1(6);
    test.pushStack1(7);
    test.pushStack2(2);
    test.pushStack2(1);
   
    cout << "Stack1 is empty? " << test.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test.isFullStack2()<< endl;
    cout << endl;
    
    cout << test.popStack1() << " popped from stack 1" << endl;
    test.display();
    
    cout << "Stack1 is empty? " << test.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test.isFullStack2()<< endl;
    cout << endl;
    
    cout << test.popStack1() << " popped from stack 1" << endl;
    test.display();
    cout << "Stack1 is empty? " << test.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test.isFullStack2()<< endl;
    cout << endl;
    
    cout << test.popStack2() << " popped from stack 2" << endl;
    cout << test.popStack2() << " popped from stack 2" << endl;
    test.display();
    cout << "Stack1 is empty? " << test.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test.isFullStack2()<< endl;
    cout << endl << endl;
   
   cout << "Tests with just a stack1 and a nonexistant stack2:" << endl << endl;
    TwoStackFixed<int> test2(6, 5);
    cout << "The non-existant stack2 should always be NOT FULL and EMPTY";
    cout << endl;
    cout << "Stack1 is empty? " << test2.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test2.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test2.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test2.isFullStack2()<< endl;
    test2.display();
    test2.pushStack1(0);
    test2.pushStack1(2);
    test2.pushStack1(4);
    test2.pushStack1(8);
    cout << "Stack1 is empty? " << test2.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test2.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test2.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test2.isFullStack2()<< endl;
     //test2.pushStack2(8); //This causes program to abort as intended.
     cout << endl;
     
    test2.pushStack1(10);
    test2.pushStack1(12);
    //test2.pushStack1(69); //This causes program to abort as intended.
    cout << "Stack1 is empty? " << test2.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test2.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test2.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test2.isFullStack2()<< endl << endl;
    
    //cout << test2.popStack2(); //This causes program to abort as intended.
    cout << test2.popStack1() << " popped from stack 1" << endl;
    cout << test2.popStack1() << " popped from stack 1" << endl;
    cout << test2.popStack1() << " popped from stack 1" << endl;
    cout << test2.popStack1() << " popped from stack 1" << endl;
    cout << test2.popStack1() << " popped from stack 1" << endl;
    cout << test2.popStack1() << " popped from stack 1" << endl;
    //cout << test2.popStack1(); //This causes program to abort as intended.
    cout << "Stack1 is empty? " << test2.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test2.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test2.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test2.isFullStack2()<< endl << endl << endl;
    
    
    cout << "Tests with just a stack2 and a nonexistant stack1:" << endl << endl;
    TwoStackFixed<int> test3(3, -1);
    cout << "Stack1 is empty? " << test3.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test3.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test3.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test3.isFullStack2() << endl;
    test3.display();
    
    //test3.pushStack1(0);  //This causes program to abort as intended.
    test3.pushStack2(-1);
    test3.pushStack2(-2);
    test3.pushStack2(-3);
    //test3.pushStack2(-4); //This causes program to abort as intended.
    cout << "Stack1 is empty? " << test3.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test3.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test3.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test3.isFullStack2() << endl << endl;
    
    //test3.popStack1(); //This causes program to abort as intended.
    cout << test3.popStack2() << " popped from stack 2" << endl;
    cout << test3.popStack2() << " popped from stack 2" << endl;
    cout << test3.popStack2() << " popped from stack 2" << endl;
    //cout << test3.popStack2();  //This causes program to abort as intended.
    cout << "Stack1 is empty? " << test3.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << test3.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << test3.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  test3.isFullStack2() << endl << endl;
    cout << "====================================================" << endl;
    cout << "Tests with TwoStackOptimal:" << endl;
    cout << "====================================================" << endl;
    cout << endl;
    
    TwoStackOptimal<int>stacks(6);
    stacks.display();
     cout << "Stack1 is empty? " << stacks.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << stacks.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << stacks.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  stacks.isFullStack2() << endl << endl;
    
    stacks.pushFlexStack1(19);
    stacks.pushFlexStack2(69);
     cout << "Stack1 is empty? " << stacks.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << stacks.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << stacks.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  stacks.isFullStack2() << endl << endl;
    
    stacks.pushFlexStack1(29);
    stacks.pushFlexStack2(59);
    stacks.pushFlexStack1(39);
    stacks.pushFlexStack2(49);
    //stacks.pushFlexStack1(15); //This causes program to abort as intended.
    //stacks.pushFlexStack2(10); //This causes program to abort as intended.
    cout << "Stack1 is empty? " << stacks.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << stacks.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << stacks.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  stacks.isFullStack2() << endl << endl;
    
    cout << "Popping " << stacks.popFlexStack1() << " from Stack1" << endl;
    stacks.display();
    cout << "Popping " << stacks.popFlexStack1() << " from Stack1" << endl;
    stacks.display();
    cout << "Popping " << stacks.popFlexStack1() << " from Stack1" << endl;
    stacks.display();
    //cout << stacks.popFlexStack1(); //This causes program to abort as intended.
    cout << "Stack1 is empty? " << stacks.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << stacks.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << stacks.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  stacks.isFullStack2() << endl << endl;
    
    cout << "Popping " << stacks.popFlexStack2() << " from Stack2" << endl;
    stacks.display();
    cout << "Popping " << stacks.popFlexStack2() << " from Stack2" << endl;
    stacks.display();
    cout << "Popping " << stacks.popFlexStack2() << " from Stack2" << endl;
    stacks.display();
    //cout << stacks.popFlexStack1(); //This causes program to abort as intended.
    cout << "Stack1 is empty? " << stacks.isEmptyStack1() << endl;
    cout << "Stack2 is empty? " << stacks.isEmptyStack2()<< endl;
    cout << "Stack1 is Full? " << stacks.isFullStack1()<< endl;
    cout << "Stack2 is Full? " <<  stacks.isFullStack2() << endl << endl;
    
    cout << "=======================" << endl;
    cout << "Tower of Hanoi tests" << endl;
    cout << "=======================" << endl;
    
    stack<int> A;
    stack<int> B;
    stack<int> C;
    A.push(3);
    A.push(2);
    A.push(1);
    
    showTowerStates(A.size(), A, B, C);
    
    return 0;
}

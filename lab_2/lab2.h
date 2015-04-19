//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab2/lab2.h
/// @brief Lab 2 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @SID: 861162817
/// @date @date 4/18/2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#ifndef LAB2_H
#define LAB2_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        Node* next;
        Node(T data) : data(data), next(0) {}
};

template <typename T>
class List
{
    private:
        Node<T>* head;
        Node<T>* tail;
        
    public:
        List();
        List(const T& str);
        ~List();
        void pop_front();
        void push_front(T value);
        void push(T value);
        void rotate(int k);
        void display();
        List<T> elementSwap(int pos);
};

int primeCount(forward_list<int> lst);
bool isPrime(int i);

template <typename T>

void listCopy(forward_list <T> L, forward_list <T> &P);

template <typename T>

void printLots(forward_list<T> L, forward_list<int> P);

#endif
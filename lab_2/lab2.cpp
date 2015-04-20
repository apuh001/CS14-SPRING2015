//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab2/lab2.cpp
/// @brief Lab 2 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 4/18/2015
/// @SID: 861162817
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

bool isPrime(int i)
{
    //These values never prime.
    if(i <= 0)
        return false;
        
    //Basic single digit prime numbers
    if(i == 2 || i == 3 || i == 5 || i == 7)
        return true;
    
    //Checks if remainder by modding i with the single digit primes
    if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
        return true;
    return false;
}

int primeCount(forward_list<int> lst)
{
    //Base case
    if(lst.empty())
        return 0;
    
    //If 1st element tested to be prime. Then recursively call whilst popping
    //first element off.
    if(isPrime(lst.front()))
    {
        lst.pop_front();
        return 1 + primeCount(lst);
    }
    
    //Implies 1st element is not prime. Then recursively call whilst popping
    //first element off.
    lst.pop_front();
    return 0 + primeCount(lst);
}

template <typename T>

//Rule: Traverse L once. Copy L into P in reverse order.
void listCopy(forward_list<T> L, forward_list<T> &P)
{
    //If L is empty or both are, nothing to do. 
    if(L.empty() || (L.empty() && P.empty()))
        return;
    
    //If just P is empty, all we do is push L's elements in reverse order.
    if(P.empty())
    {
        while(!(L.empty()))
        {
            P.insert_after(P.cbefore_begin(), L.front());
            L.pop_front();
        }
    }
    else
    {
        //Gets an iterator pointing to end() - 1
        auto iter = P.cbegin();
        //oneBehind will be pointing to the space BEFORE the mystical end().
        //This ensures insert_after works without segfaulting. 
        auto oneBehind = P.cbegin();
        for(; iter != P.cend(); iter++)
        {
            if(iter != P.cbegin())
                oneBehind++;
        }
    
        //Insert the front element into the space next to the last element of
        //forward_list P.
        while(!(L.empty()))
        {
            P.insert_after(oneBehind, L.front());
            L.pop_front();
        }
    }
    return;
}

template <typename T>

void printLots(forward_list<T> L, forward_list<int> P)
{
    //Both lists empty.
    if(P.empty() && L.empty())
        return;
    
    //L is already empty, but P is not empty.
    if(!(P.empty()) && L.empty())
    {
        cout << endl;
        cout << "Error: P contains out of boundary positions in L." << endl;
        return;
    }    
    
    int counter = -1;
        
    //P and L already have elements. Or if P had no elements to begin with
    //and L has elements, nothing will be printed.
    while(!(P.empty()))
    {
        counter++;
        
        //If our position matches with the counter
        if(P.front() == counter)
        {
            //Gets rid of first element to advance front() to next.
            P.pop_front();
            //DO WE NEED BETTER FORMATTING?
            cout << L.front() << " ";
        }
        
        L.pop_front();
        
        //If P is not empty, while L is already empty, we have out of range
        //elements!
        if(!(P.empty()) && L.empty())
        {
            cout << endl;
            cout << "Error: P contains out of boundary positions in L." << endl;
            return;
        }
    }
    return;
}
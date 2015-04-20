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


//NOTE! MAIN FUNCTION IS LOCATED AT BOTTOM.

#include "lab2.h"
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

int main()
{
    cout << "=====================" << endl;
    cout << "elementSwap() TESTS" << endl;
    cout << "=====================" << endl << endl;
    
    List<int> myList;
    //Push back several ints. and Print.
    for(unsigned i = 0; i < 6; i++)
        myList.push(i);
    cout << "myList contains: " << endl;
    myList.display();
    cout << endl << endl;
    cout << "Testing  myList.elementSwap(0)" << endl;
    myList.elementSwap(0);
    myList.display();
    cout << endl;
    cout << "Testing  myList.elementSwap(5)" << endl;
    myList.elementSwap(5);
    myList.display();
    cout << endl;
    cout << "Testing  myList.elementSwap(-1)" << endl;
    myList.elementSwap(-1);
    myList.display();
    cout << endl;
    cout << "Testing  myList.elementSwap(3)" << endl;
    myList.elementSwap(3);
    myList.display();
    cout << endl;
    cout << "Testing  myList.elementSwap(4)" << endl;
    myList.elementSwap(4);
    myList.display();
    cout << endl;
    cout << "Testing  myList.elementSwap(0)" << endl;
    myList.elementSwap(0);
    myList.display();
    cout << endl;
    cout << "Testing  myList.elementSwap(5)" << endl;
    myList.elementSwap(5);
    myList.display();
    cout << endl << endl;
    
    List<int> emptyList;
    cout << "Using an emptyList..." << endl;
    cout << "Testing  emptyList.elementSwap(5)" << endl;
    emptyList.elementSwap(5);
    emptyList.display();
    cout << endl;
    cout << "Testing  emptyList.elementSwap(0)" << endl;
    emptyList.elementSwap(0);
    emptyList.display();
    cout << endl;
    cout << "Testing  emptyList.elementSwap(-1)" << endl;
    emptyList.elementSwap(-1);
    emptyList.display();
    cout << endl << endl;
    
    List<int> aList(6);
    cout << "Using aList with a single int, 6..." << endl;
    cout << "Testing  aList.elementSwap(5)" << endl;
    aList.elementSwap(5);
    aList.display();
    cout << endl;
    cout << "Testing  aList.elementSwap(0)" << endl;
    aList.elementSwap(0);
    aList.display();
    cout << endl;
    cout << "Testing  aList.elementSwap(1)" << endl;
    aList.elementSwap(1);
    aList.display();
    cout << endl;
    cout << "Testing  aList.elementSwap(-1)" << endl;
    aList.elementSwap(-1);
    aList.display();
    cout << endl << endl;
    
    cout << "==================================" << endl;
    cout << "primeCount() and isPrime() TESTS" << endl;
    cout << "==================================" << endl << endl;
    
    cout << "Testing isPrime()..." << endl << endl;
    
    for(int i = -7; i < 16; i++)
    {
        cout << i << " is ";
        if(!isPrime(i))
            cout << "not";
        cout << " prime." << endl;
    }
    
    //Testing with largest possible prime number.
    cout << "257,885,161 is ";
        if(!isPrime(257885161))
            cout << "not";
        cout << " prime." << endl;
    cout << endl;
    
    cout << "Testing with a list of random numbers. (5 are prime)" << endl;
    forward_list<int> numList;
    numList.push_front(5);
    numList.push_front(11);
    numList.push_front(2424);
    numList.push_front(991);
    numList.push_front(-23);
    numList.push_front(0);
    numList.push_front(1);
    numList.push_front(2);
    numList.push_front(-100);
    numList.push_front(0);
    numList.push_front(555);
    
    
    cout << "Number of primes: " << primeCount(numList) << endl;
    cout << "To verify, we'll also check each individually:" << endl;
    
    while(!numList.empty())
    {
        cout << numList.front() << " is ";
        if(!isPrime(numList.front()))
            cout << "not";
        cout << " prime." << endl;
        
        numList.pop_front();
    }
    
    cout << endl;
    
    cout << "Testing with an empty list." << endl;
    cout << "Number of primes: " << primeCount(numList) << endl;
    cout << endl;
    
    cout << "Testing with list of 1 prime number (13)" << endl;
    numList.push_front(13);
    cout << "Number of primes: " << primeCount(numList) << endl;
    numList.pop_front();
    cout << endl;
    
    cout << "Testing with list of 1 non-prime number (77)" << endl;
    numList.push_front(77);
    cout << "Number of primes: " << primeCount(numList) << endl;
    cout << endl;
    
    cout << "Testing with list of (77, 88, 99, 100, 44, 35)" << endl;
    numList.push_front(77);
    numList.push_front(88);
    numList.push_front(99);
    numList.push_front(100);
    numList.push_front(44);
    numList.push_front(35);
    cout << "Number of primes: " << primeCount(numList) << endl;
    numList.clear();
    cout << endl;
    
    cout << "Testing with list of (77, 11)" << endl;
    numList.push_front(77);
    numList.push_front(11);
    cout << "Number of primes: " << primeCount(numList) << endl;
    cout << endl;
    
    cout << "==================================" << endl;
    cout << "listCopy() TESTS" << endl;
    cout << "==================================" << endl << endl;
    
    forward_list<char> letters;
    forward_list<char> ints;
    letters.push_front('d');
    letters.push_front('c');
    letters.push_front('b');
    letters.push_front('a');
    ints.push_front('4');
    ints.push_front('3');
    ints.push_front('2');
    ints.push_front('1');
    cout << endl;
    
    cout << "forward_list letters contains (a,b,c,d)";
    cout << " and ints contains (1,2,3,4)" << endl;
    cout << "After using listCopy(ints, letters)..." << endl;
    listCopy(ints, letters);
    cout << endl;
    cout << "ints now contains: " << endl;
    while(!ints.empty())
    {
        cout << ints.front() << " ";
        ints.pop_front();
    }
    cout << endl;
    cout << "letters now contains: " << endl;
    while(!letters.empty())
    {
        cout << letters.front()  << " ";
        letters.pop_front();
    }
    cout << endl << endl;
    
    cout << "Testing with empty lists. listCopy(empty1,empty2)" << endl;
    forward_list<int> empty1;
    forward_list<int> empty2;
    listCopy(empty1,empty2);
    cout << "empty2 now contains: " << endl;
    if(empty2.empty())
        cout << "[No elements]" << endl;
    cout << "empty1 now contains: " << endl;
    if(empty1.empty())
        cout << "[No elements]" << endl;
    cout << endl;
    
    cout << "Testing with empty1 and nums-> (1, 2, 3, 4, 5, 6, 7, 8)" << endl;
    cout << "listCopy(empty1,nums)" << endl;
    forward_list<int> nums;
    for(unsigned x = 9; x > 0; x--)
        nums.push_front(x);
    listCopy(empty1,nums);
    cout << "empty1 now contains: " << endl;
    if(empty1.empty())
        cout << "[No elements]" << endl;
    cout << "nums now contains: " << endl;
    while(!nums.empty())
    {
        cout << nums.front()  << " ";
        nums.pop_front();
    }
    cout << endl << endl;
    
    cout << "Testing with empty1 and nums-> (1, 2, 3, 4, 5, 6, 7, 8)" << endl;
    cout << "listCopy(nums,empty1) <--- notice flipped from last" << endl;
    for(unsigned x = 9; x > 0; x--)
        nums.push_front(x);
    listCopy(nums, empty1);
    cout << "empty1 now contains: " << endl;
    if(empty1.empty())
        cout << "[No elements]" << endl;
    else
    {
        while(!empty1.empty())
        {
            cout << empty1.front()  << " ";
            empty1.pop_front();
        }
    }
    cout << endl;
    cout << "nums now contains: " << endl;
    while(!nums.empty())
    {
        cout << nums.front()  << " ";
        nums.pop_front();
    }
    cout << endl << endl;
    
    cout << "==================================" << endl;
    cout << "printLots() TESTS" << endl;
    cout << "==================================" << endl << endl;
    
    forward_list<char> charList;
    forward_list<int> indexList;
    indexList.push_front(5);
    indexList.push_front(3);
    indexList.push_front(1);
    indexList.push_front(0);
    charList.push_front('f');
    charList.push_front('e');
    charList.push_front('d');
    charList.push_front('c');
    charList.push_front('b');
    charList.push_front('a');
    
    cout << endl;
    cout << "Testing indexList(0, 1, 3, 5) with charList(a,b,c,d,e,f)" << endl;
    cout << "Expected: a b d f" << endl;
    cout << "Result: ";
    printLots(charList, indexList);
    cout << endl << endl;
    
    forward_list<int> index2List;
    index2List.push_front(8);
    index2List.push_front(0);
    cout << "Testing index2List(0, 8) with charList(a,b,c,d,e,f)" << endl;
    cout << "Expected: a [error message]" << endl;
    cout << "Result: ";
    printLots(charList, index2List);
    cout << endl << endl;
    
    index2List.clear();
    cout << "Testing index2List([empty]) with charList(a,b,c,d,e,f)" << endl;
    cout << "Expected: [nothing printed]" << endl;
    cout << "Result: ";
    printLots(charList, index2List);
    cout << endl << endl;
    
    index2List.clear();
    charList.clear();
    cout << "Testing index2List([empty]) with charList([empty])" << endl;
    cout << "Expected: [nothing printed]" << endl;
    cout << "Result: ";
    printLots(charList, index2List);
    cout << endl << endl;
    
    cout << "Testing indexList(0, 1, 3, 5) with charList([empty])" << endl;
    cout << "Expected: [error message]" << endl;
    cout << "Result: ";
    printLots(charList, indexList);
    cout << endl << endl;
    
    indexList.push_front(-1);
    cout << "Testing indexList(-1) with charList([empty])" << endl;
    cout << "Expected: [error message]" << endl;
    cout << "Result: ";
    printLots(charList, indexList);
    cout << endl << endl;
    
    charList.push_front(-2);
    charList.push_front(-1);
    cout << "Testing indexList(-1) with charList(a, b)" << endl;
    cout << "Expected: [error message]" << endl;
    cout << "Result: ";
    printLots(charList, indexList);
    cout << endl << endl;
    
    indexList.clear();
    for(int n = 5; n >= 0; n--)
        indexList.push_front(n);
    
    charList.clear();
    charList.push_front('z');
    charList.push_front('y');
    charList.push_front('x');
    charList.push_front('c');
    charList.push_front('b');
    charList.push_front('a');
    cout << "Testing indexList(0, 1, 2, 3, 4, 5)";
    cout << " with charList(a, b, c, x, y, z)" << endl;
    cout << "Expected: a b c x y z" << endl;
    cout << "Result: ";
    printLots(charList, indexList);
    cout << endl << endl;
    
    charList.push_front('z');
    cout << "Testing indexList(0, 1, 2, 3, 4, 5)";
    cout << "with charList(z ,a, b, c, x, y, z)" << endl;
    cout << "Expected: z a b c x y " << endl;
    cout << "Result: ";
    printLots(charList, indexList);
    cout << endl << endl;
    
    return 0;
}
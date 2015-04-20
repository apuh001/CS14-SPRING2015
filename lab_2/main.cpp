#include "lab2.h"
#include "lab2.cpp"
#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

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
    
    
    return 0;
}
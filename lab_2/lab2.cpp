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

#include "lab2.h"
#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

template <typename T>

List<T>::List()
{
    head = 0;
    tail = 0;
}

template <typename T>

List<T>::List(const T& str)
{
    head = new Node<T>(str);
    tail = head;
    tail->next = 0;
    head->next = 0;
}

template <typename T>

List<T>::~List()
{
    while(head != 0)
    {
        pop_front();
    }
}

template <typename T>

void List<T>::pop_front()
{
    //If it stores 0, we can't delete later. This condition helps.
    if(head == 0)
        return;
        
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    temp = 0;
    
    if (head == 0)
        tail = 0;
}
    
template <typename T>

void List<T>::push_front(T value)
{
    if(head == 0)
    {
        head = new Node<T>(value);
        tail = head;
        
        return;
    }

    Node<T>* oldHead = head;
    Node<T>* newHead = new Node<T>(value);
    head = newHead;
    head->next = oldHead;
    newHead = 0;
    oldHead = 0;
    
    Node<T>* curr = head;
    while (curr != 0)
    {
        if (curr->next == 0)
            tail = curr;
            
        curr = curr->next;
    }
}

template <typename T>

void List<T>::push(T value)
{
    if(head == 0)
    {
        head = new Node<T>(value);
        tail = head;
        
        return;
    }

    Node<T>* temp = tail;
    tail = new Node<T>(value);
    tail->next = 0;
    
    temp->next = tail;
    temp = 0;
    
    return;
}

template <typename T>

void List<T>::rotate(int k)
{
    //Empty lists
    if(head == 0)
    {
        //cout << "empty list" << endl;
        return;
    }
        
    //Border case k = 0 or less
    //No rotation should occur if k refers to first
    //position 0.
    if(k <= 0)
    {
        //cout << "index too small" << endl;
        return;
    }
    
    //Find the kth Node.
    int indexCount = -1;
    Node<T>* kthNode = NULL;
    Node<T>* kthPrevNode = NULL;
    Node<T>* curr = head;
    for(; curr != 0; curr = curr->next)
    {
        //cout << "index count: " << indexCount << endl;
        indexCount++;
        
        if(indexCount == (k - 1))
            kthPrevNode = curr;
            
        if(indexCount == k)
            kthNode = curr;
    }
    
    //kthNode hasn't changed. k was too large.
    if(kthNode == NULL)
    {
        //cout << "too large?" << endl;
        return;
    }
    
    //Proceed to rotate.
    //First check for a List if k is tail
    if(kthNode->next == 0)
    {
        //cout << "went into tail check!" << endl;
        kthNode->next = head;
        head = kthNode;
        tail = kthPrevNode;
        kthPrevNode->next = 0;
        
        return;
    }
    
    //cout << "last check!" << endl;
    //This should handle correctly as kthNode is not tail.
    //Fast reassignment of next and new head and tail values.
    tail->next = head;
    head = kthNode;
    tail = kthPrevNode;
    tail->next = 0;
    
    return;
}

template <typename T>

void List<T>::display()
{
    Node<T>* curr;
    
    for (curr = head; curr !=0; curr = curr->next)
    {
        cout << curr->data;
    }
}

template <typename T>

List<T> elementSwap(int pos)
{
    int posCount = -1;
    Node* pos1Node = 0;
    Node* posN1Node = 0;
    Node* tempPrevious = 0;
    
    //If the next element is 0, then return original list w/o swap
    for (curr = head; curr->next !=0; curr = curr->next)
    {
        posCount++;
        
        //Previous node
        if(posCount == pos - 1)
            tempPrevious = curr;
            
        if(posCount == pos)
        {
            pos1Node = curr;
            posN1Node = curr->next;
            Node* temp = posN1Node->next;
            
            if(pos1Node == head)
            {
                pos1Node->next = temp;
                posN1Node->next = post1Node;
                
                head = posN1Node;
                
                return *this;
            }
            if(posN1Node == tail)
            {
                pos1Node->next = temp;
                posN1Node->next = post1Node;
                tempPrevious->next = posN1Node;
                
                tail = pos1Node;
                
                return *this;
            }
            
            //Swaps occuring inside not head or tail.
            pos1Node->next = temp;
            posN1Node->next = post1Node;
            tempPrevious->next = posN1Node;
            
            return *this;
        }
        
    }
    
    //No swap occured.
    return *this;
}

int primeCount(forward_list<int> 1st);
{
    //Base case
    if(1st.empty())
        return 0;
    
    //If 1st element tested to be prime. Then recursively call whilst popping
    //first element off.
    if(isPrime(1st.front()))
        return 1 + primeCount(1st.pop_front());
    
    //Implies 1st element is not prime. Then recursively call whilst popping
    //first element off.
    return 0 + primeCount(1st.pop_front());
}

bool isPrime(int i)
{
    //Basic single digit prime numbers
    if(i == 2 || i == 3 || i == 5 || i == 7)
        return true;
    
    //Checks if remainder by modding i with the single digit primes
    if(i % 2 != 0 || i % 3 != 0 || i % 5 != 0|| i % 7 != 0)
        return true;
    return false;
}

//Rule: Traverse L once. Copy L into P in reverse order.
//NEEDS WORK
void listCopy(forward_list<T> L, forward_list<T> P)
{
    forward_list<T>::iterator fwdListIt = L.end();
    forward_list<T>::iterator PIt = P.end();
    
    //Points iterator to last element.
    PIt--;
    fwdListIt--;
    
    while(!(L.empty()))
    {
        P.insert_after(P.end, L.front());
        L.pop_front();
    }
    
    return;
}

void printLots(forward_list<T> L, forward_list<int> P)
{
    int counter = -1;

    //Both lists empty.
    if(P.empty() && L.empty())
        return;
    
    //L is already empty, but P is not empty.
    if(!(P.empty()) && L.empty()
    {
        cout << "Error: P contains out of boundary positions in L" << endl;
        return;
    }    
    
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
            cout << L.front() << endl;
            //Gets rid of first element to advance front() to next.
            P.pop_front();
        }
        
        //If P is not empty, while L is already empty, we have out of range
        //elements!
        if(!(P.empty()) && L.empty())
        {
            cout << "Error: P contains out of boundary positions in L" << endl;
            return;
        }
    }
    return;
}
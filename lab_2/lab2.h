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
    
        List()
        {
            head = 0;
            tail = 0;
        }
        
        List(const T& str)
        {
            head = new Node<T>(str);
            tail = head;
            tail->next = 0;
            head->next = 0;
        }
        
        ~List()
        {
            while(head != 0)
            {
                pop_front();
            }
        }
        
        void pop_front()
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
        
        void push_front(T value)
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

        void push(T value)
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
        
        void display()
        {
            Node<T>* curr;
            
            for (curr = head; curr !=0; curr = curr->next)
            {
                cout << curr->data;
            }
        }
        
        //If position is out of range, nothing is changed.
        void elementSwap(int pos)
        {
            if(this->head == 0)
            {
                //No swap occured.
                cout << "No swap was made because invalid position "; 
                cout << pos << " was passed." << endl;
                return;
            }
            
            int posCount = -1;
            Node<T>* pos1Node = 0;
            Node<T>* posN1Node = 0;
            Node<T>* tempPrevious = 0;
            
            //If the next element is 0, then return original list w/o swap
            for (Node<T>* curr = this->head; curr->next !=0; curr = curr->next)
            {
                posCount++;
                
                //Previous node
                if(posCount == pos - 1)
                    tempPrevious = curr;
                    
                if(posCount == pos)
                {
                    pos1Node = curr;
                    posN1Node = curr->next;
                    Node<T>* temp = posN1Node->next;
                    
                    if(pos1Node == head)
                    {
                        pos1Node->next = temp;
                        posN1Node->next = pos1Node;
                        
                        head = posN1Node;
                        
                        return;
                    }
                    if(posN1Node == tail)
                    {
                        pos1Node->next = temp;
                        posN1Node->next = pos1Node;
                        tempPrevious->next = posN1Node;
                        
                        tail = pos1Node;
                        
                        return;
                    }
                    
                    //Swaps occuring inside not head or tail.
                    pos1Node->next = temp;
                    posN1Node->next = pos1Node;
                    tempPrevious->next = posN1Node;
                    
                    return;
                }
                
            }
            
            //No swap occured.
            cout << "No swap was made because invalid position "; 
            cout << pos << " was passed." << endl;
          
            return;
        }
};

#endif
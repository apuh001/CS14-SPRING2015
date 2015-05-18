//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab6/selectionsort.h
/// @brief Lab 6 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 5/17/2015
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
#include <utility>
#include <vector>
#include <list>
#include <tuple>
#include <typeinfo>

using namespace std;

#ifndef SEL_SORT_H
#define SEL_SORT_H

template<typename fVal, typename sVal>
void printHelp(const pair<fVal, sVal> aPair){
    cout << "(" << aPair.first << "," << aPair.second << ") ";
}

template<typename T>
void printHelp(T val)
{
    cout << val << " ";
}

template<typename L>
void printContainer(L &l)
{
    for(auto it = l.begin(); it != l.end(); it++)
        printHelp(*it);
    cout << endl;
    
    //
    //string asd = typeid(l).name();
    //if(asd.find("vector") != string::npos || 
    //   asd.find("list") != string::npos)
    // 
}

template<typename L>
void selectionsort(L &l)
{
    string asd = typeid(l).name();
    
    if(asd.find("vector") != string::npos || 
       asd.find("list") != string::npos)
    {
        cout << "pre: ";
        //Prints intial contents
        printContainer(l);
        
        //Count for number of swaps
        int count = 0;
        
        for(auto it = l.begin(); it != l.end(); it++)
        {
            auto min = it;
            for(auto it2 = it; it2 != l.end(); it2++)
            {
                if(*it2 < *min)
                    min = it2;
            }
            //Don't swap unless necessary
            if(min != it)
            {
                swap(*min, *it);
                count++;
            }
        }
        //Prints final contents and how many moves were made
        cout << "post: ";
        printContainer(l);
        cout << "0 copies and " << count << " moves" << endl;
    }
}

#endif
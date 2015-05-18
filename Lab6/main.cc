//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab6/main.cc
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

#include <tuple>
#include <vector>
#include <list>
#include "selectionsort.h"


using namespace std;

int main(){
    

    vector<int> nums {2, 4, 5, 1, 8, 9};
    selectionsort(nums);
    
    //default
    std::list<int> nums2;
    selectionsort(nums2);

    // list<pair<int, int>> aList{{pair<int, int>(1, 2)}, {pair<int, int>(3, -1)}
    //     {pair<int, int>(-1, 3)}, {pair<int, int>(0, 0)}, {pair<int, int>(2, 3)}
    //     {pair<int, int>(1, 2)}, {pair<int, int>(1, -2)}, 
    //     {pair<int, int>(8, 10)}};
    list<pair<int, int>> aList{{pair<int, int>(1, 2)}, {pair<int, int>(3, -1)},
        {pair<int, int>(-1, 3)}, {pair<int, int>(0, 0)}, {pair<int, int>(2, 3)},
        {pair<int, int>(1, 2)}, {pair<int, int>(1, -2)}, {pair<int, int>(8, 10)}
        };
    selectionsort(aList);
    
    vector<pair<int, int>> aVec{{pair<int, int>(10, 2)}, 
                                {pair<int, int>(-3, -1)},
                                {pair<int, int>(-8, 0)}, 
                                {pair<int, int>(1, 1)}, {pair<int, int>(1, 1)},  
                                {pair<int, int>(0, 0)}, 
                                {pair<int, int>(10, 2)}, 
                                {pair<int, int>(5, 5)}, 
                                {pair<int, int>(5, -5)}, {pair<int, int>(0, 0)}, 
                                {pair<int, int>(10, 2)}};
    selectionsort(aVec);
    
    list<pair<int, int>> aList2{{pair<int, int>(-1, 3)}, {pair<int, int>(0, 0)},
        {pair<int, int>(1, -2)}, {pair<int, int>(1, 2)}, {pair<int, int>(1, 2)},
        {pair<int, int>(2, 3)}, {pair<int, int>(3, -1)}, {pair<int, int>(8, 10)}
        };
        
    selectionsort(aList2);
    
    return 0;
}
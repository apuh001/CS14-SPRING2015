//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab4/lab4.h
/// @brief Lab 4 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 4/27/2015
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
#include <queue>
#include <tuple>

using namespace std;

void list_preorder(int m, int n, int k)
{
    if(m + n >= k)
        return;
    
    cout << m << " " << n << endl;
    list_preorder((2*m)-n, m, k); 
    list_preorder((2*m)+n, m, k);
    list_preorder(m+(2*n), n, k);
}

void list_postorder(int m, int n, int k)
{
    if(m + n >= k)
        return;
    //Checks to see if "leaf"
    if(((m+(2*n) + n) >= k) && (((2*m)+n + m) >= k) && (((2*m)-n + m) >= k))
    {
        cout << m << " " << n << endl;
        return;
    }
    
    list_postorder((2*m)-n, m, k);
    list_postorder((2*m)+n, m, k);
    list_postorder(m+(2*n), n, k);
     
    cout << m << " " << n << endl;
}

struct pair_comp_greater{
    bool operator() (const pair<int, int> &first, 
    const pair<int, int> &second) const
    {
        //If sums identical, then look at the first vals
        if((get<0>(first) + get<1>(first)) == 
            (get<0>(second) + get<1>(second)))
            return ((get<0>(first) > get<0>(second)));
        return ((get<0>(first) + get<1>(first)) > 
                (get<0>(second) + get<1>(second)));
    }
};

void obtain_store_vals(int m, int n, int k, priority_queue<pair<int, int>, 
vector<pair<int, int>>, pair_comp_greater> &ordered)
{
    if(m + n >= k)
        return;
    pair<int, int> aPair(m, n);
    ordered.push(aPair);
    obtain_store_vals((2*m)-n, m, k, ordered); 
    obtain_store_vals((2*m)+n, m, k, ordered);
    obtain_store_vals(m+(2*n), n, k, ordered);
}

//Uses a priority queue to sort
void list_sortedorder(int m1, int m2, int n, int k)
{
   //priority_queue<pair<int, int>, vector<pair<int, int>>, 
   //greater<pair<int, int>>> allVals;
   
   priority_queue<pair<int, int>, vector<pair<int, int>>, 
   pair_comp_greater> allVals;
   
   obtain_store_vals(m1, n, k, allVals);
   obtain_store_vals(m2, n, k, allVals);
 
   while(!allVals.empty())
   {
       cout << get<0>(allVals.top());
       cout << " " << get<1>(allVals.top()) << endl;
       allVals.pop();
   }
  
   return;
}
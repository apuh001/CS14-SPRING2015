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
using namespace std;
/*
class CoprimeNode
{
    public:
        int mVal;
        int nVal;
        CoprimeNode* child1; 
        CoprimeNode* child2; 
        CoprimeNode* child3; 
        //CoprimeNode()
        void list_preorder();
        void list_postorder();
        
}
*/

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

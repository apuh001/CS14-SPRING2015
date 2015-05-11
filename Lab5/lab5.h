//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab5/lab5.h
/// @brief Lab 5 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 5/4/2015
/// @SID: 861162817
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#ifndef BST_H
#define BST_H
#define TEST

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

#define nil 0

//#define Value int //Testing
template <typename Value>

class BST{
    class Node{
        public:
            Value value;
            bool selected = false;
            Node* left;
            Node* right;
            Node(const Value v = Value()) : value(v), 
                                            left(nil), right(nil){}
            Value& content(){return value;}
            bool isInternal(){return left != nil && right != nil;}
            bool isExternal(){return left != nil || right != nil;}
            bool isLeaf(){return left == nil && right == nil;}
            
            //Helper
            int size_subtree(Node* n)
            {
                if(n == nil)
                    return 0;
                if(n->left == nil && n->right == nil)
                    return 1;
        
                //Counts itself then recursive call on its left and right nodes
                return 1 + size_subtree(n->left) + size_subtree(n->right);
            }
    
            //size of subtree rooted at this node
            int size(){
                //This node exists but has no left or right
                if(left == nil && right == nil)
                    return 1;
                return 1 + size_subtree(root->right) + size_subtree(root->left);
            }
            
            int height_(Node* curr){
                //Base cases check to see if the next traversal exists or not
                if(curr == nil)
                    return -1;
                if(curr->isLeaf())
                    return 1;
                //Left count and right count keep track 
                int leftCount = 1 + height_(curr->left);
                int rightCount = 1 + height_(curr->right);
                
                //Returns the greatest path
                return static_cast<int>(fmax(leftCount, rightCount));
            }
            
            //WORKING
            int height(){
                //height of sub tree rooted at this node
                if(this == nil)
                    return 0;
                
                //Returns counting the calling node and it's max of either 
                //left or right subtree
                return 1 + static_cast<int>
                (fmax(height_(this->right), height_(this->left)));
            }
            
    };
    
    //const Node* nil; //later nil will point to a sentinel value
    int count;
   
    
    
    ///////// PRIVATE HELPER FUNCS ////////////
    
    int size_subtree(Node* n)
    {
        if(n == nil)
            return 0;
        if(n->left == nil && n->right == nil)
            return 1;
        
        //Counts itself then recursive call on its left and right nodes
        return 1 + size_subtree(n->left) + size_subtree(n->right);
    }
    
    //Helper for opeator[]
    void subscript_helper(Node* n, vector<Node*> &vals){
        if(n == nil)
            return;
            
        if(n->isLeaf())
        {
            vals.push_back(n);
            return;
        }
        
        // In order push_back of vals.
        subscript_helper(n->left, vals);
        vals.push_back(n);
        subscript_helper(n->right, vals);
    }
    
    void preorder_(Node* n)const
    {
        if(n == nil)
            return;
            
        if(n->isLeaf())
        {
            cout << n->value << endl;
            return;
        }
        
        cout << n->value << endl;
        preorder_(n->left);
        preorder_(n->right);
    }
    
    void postorder_(Node* n)const
    {
        if(n == nil)
            return;
            
        if(n->isLeaf())
        {
            cout << n->value << endl;
            return;
        }
        
        //Check left and right for leaves (left first, then right)
        //THEN print the internal node
        postorder_(n->left);
        postorder_(n->right);
        cout << n->value << endl;
    }
    
     void inorder_(Node* n)const{
        if(n == nil)
            return;
            
        if(n->isLeaf())
        {
            cout << n->value << endl;
            return;
        }
        
        // In order... Leftmost FIRST, then the parent, and then the
        //right subtree.
        inorder_(n->left);
        cout << n->value << endl;
        inorder_(n->right);
    }
    
    void displayMinCover_ (Node* n, int &count)const
    {
        if(n == nil)
            return;
            
        if(n->isLeaf() && n->selected)
        {
            count++;
            cout << n->value << endl;
            return;
        }
        
        //Inorder traversal to check cover npdes
        displayMinCover_(n->left, count);
        if(n->selected)
        {
            count++;
            cout << n->value << endl;
        }
            
        displayMinCover_(n->right,count);
    }
    
    void minCover_(Node* n, bool selectAsCover = true)
    {
        //Root will never be passed in.
        if(n->isLeaf() || n == nil)
            return;
        
        //requirement regardless if selectAsCover is true or false
        if(n->left != nil && n->left->isLeaf())
            n->selected = true;
        if(n->right != nil && n->right->isLeaf())
            n->selected = true;
        
        //If the above steps were not done check to see if it is a cover node 
        //or not
        if(!n->selected)
        {
            if(selectAsCover)
                n->selected = true;
        }
        
        //Flips select
        selectAsCover = !selectAsCover;
        minCover_(n->right, selectAsCover);
        minCover_(n->left, selectAsCover);
    }
    
    //Use with findSumePath
    void printBuffer(int sum, int buffer[])
    {
        int i = 0;
        for(; sum > 0; i++)
            sum-=buffer[i];
        
        i--;
        
        for(; i >= 0; i--)
            cout << buffer[i] << " ";
        
        return;
    }
    
    //Helper! Use with findSumPath
    void fillStartingFrom(Node* n, int &copySum, int sum, int buffer[],
    int &bufferIndex){
        if(n == nil)
            return;
        
        //First check left side if initially starting at node n doesn't
        //yield intended result. If left doesn't work result the value and
        //check the right side. Whatever happens will return and originally
        //calling function will handle the rest.
        fillBuffer(n->left, copySum, sum, buffer, bufferIndex);
        if(copySum != sum)
            copySum = 0;
        fillBuffer(n->right, copySum, sum, buffer, bufferIndex);
        
        return;
    }
    
    //Helper! Use with findSumPath
    void fillBuffer(Node* n, int &currSum, int origSum, int buffer[], 
    int &bufferIndex)
    {
        //If sum is equal or larger, returns. It'll be checked
        if(currSum >= origSum || n == nil)
            return;
            
        if(currSum + n->value <= origSum)
        {
            buffer[bufferIndex] = n->value;
            bufferIndex++;
            currSum+=n->value;
            //We are done
            if(currSum == origSum)
                return;
            //Otherwise go on
        }
        
        int currIndex = bufferIndex;
        int tempCurrSum = currSum;
        
        //Check left
        fillBuffer(n->left, currSum, origSum, buffer, bufferIndex);
        //Restore value if its greater. Instead, we'll check right
        if(currSum > origSum)
        {
            bufferIndex = currIndex;
            currSum = tempCurrSum;
        }
        else if(currSum < origSum)
        {
            //Check right
            fillBuffer(n->left, currSum, origSum, buffer, bufferIndex);
        }
        
        return;
    }
    
    void vertSum_(Node* n, int hd, map<int, int>& m)
    {
        if(n == nil)
            return;
        if(n->isLeaf())
        {
            if(m.find(hd) != m.end())
            {
                m[hd] = n->value;
            }
            else
                m[hd]+=n->value;
                
            return;
        }
        
        vertSum_(n->left, hd - 1, m);
        vertSum_(n->right, hd + 1, m);
        
        return;
    }
    
    void printVertSum(map<int, int>& m)
    {
        //Empty? Do nothing
        if(m.empty())
            return;
        //Print through map
        for(auto it = m.begin(); it != m.end(); it++)
            cout << it->second << " ";
        cout << endl;
    }
    ///////END OF PRIVATE HELPER FUNCS////////////
    
    
    public:
    
        Node* root;
         
         
        void vertSum(Node* node, int hd, map<int, int>& m)
        {
            cout << "Part 3" << endl;
            if(node == nil)
                return;
            else
            {
                vertSum_(node->left, hd - 1, m);
                vertSum_(node->right, hd + 1, m);       
            }
            
            printVertSum(m);
        }
        
        
        
        void findSumPath(Node* n, int sum, int buffer[])
        {
            cout << "Part 2" << endl;
            if(n == nil)
            {
                cout << "0" <<  endl;
                return;
            }
            
            int copySum = 0;
            int bufferIndex = 0;
            fillBuffer(n, copySum, sum, buffer, bufferIndex);
            
            //Reset
            if(copySum != sum)
            {
                copySum = 0;
                bufferIndex = 0;
                fillStartingFrom(n, copySum, sum, buffer, bufferIndex);
            }
            
            //No existing path
            if(copySum != sum)
                cout << "0" <<  endl;
            else
            {
                printBuffer(sum, buffer);
                cout << endl;
            }
        }
        
        void minCover()
        {
            cout << "Part 1" << endl;
            //No possible cover
            if(root == nil || root->isLeaf())
                return;
            minCover_(root->right, true);
            minCover_(root->left, true);
            return;
        }
        
        void displayMinCover()
        {
            int coverCount = 0;
            
            if(root == nil)
            {
                cout << coverCount << endl;
                return;
            }
        
            displayMinCover_(root->left, coverCount);
            displayMinCover_(root->right, coverCount);
            
            cout << coverCount << endl;
            
            return;
        }
        
        int size(){
            if(root == nil)
                return 0;
            
            //size of tree
            count = 1 + size_subtree(root->right) + size_subtree(root->left);
            return 1 + size_subtree(root->right) + size_subtree(root->left);
        }
    
        bool empty(){
            return size() == 0;
        }
        
        void print_node(const Node* n)
        {
            //print node's VALUE
            //Formatting with spaces and endl will be up to print functions.
            cout << n->value;
            return;
        }
        
        bool search(Value x)
        {
            //search for value, if found returns true
            //If root is nil
            if(root == nil)
                return false;
            
            Node* curr = root;
            while (curr != nil)
            {
                if(x < curr->value)
                {
                    if(curr->left != nil)
                        curr = curr->left; 
                    else return false;
                }    
                else if(x > curr->value)
                {
                    if(curr->right != nil)
                        curr = curr->right;
                    else return false;
                }
                else if(x == curr->value)
                    return true;
            }
    
            //Return nil if all else fails
            return nil;
        }
        
        void preorder()const{
            //Traverse tree print one value per line in preorder
            if(root == nil)
                return;
            cout << root->value << endl;
            preorder_(root->left);
            preorder_(root->right);
        }
        
        void postorder()const{
            //Traverse and print tree one val per line in postorder
            if(root == nil)
                return;
            postorder_(root->left);
            postorder_(root->right);
            cout << root->value << endl;
        }
        
        void inorder()const{
            //traverse and print one val per line in inorder
            if(root == nil)
                return;
            inorder_(root->left);
            cout << root->value << endl;
            inorder_(root->right);
        }
        
        //WORKING
        //return reference to value field of nth node
        Value& operator[](int n)
        {
            assert(root != nil);
            assert(n >= 0);
            assert(n < size());
            //if the size of the left subtree is smaller than the index number,
            //indicates that n is either the root or in the right subtree
            
            vector<Node*> nodeVal;
            subscript_helper(root->left, nodeVal);
            nodeVal.push_back(root);
            subscript_helper(root->right, nodeVal);
            
            return nodeVal[n]->value;
        }
        
        //Default constructor
        BST():count(0), root(nil){}
        
        //STUDY THIS! NODE INSERTION
        void insert(Value X){
            root = insert(X, root);
        }
        
        Node* insert(Value X, Node* T){
            //Normal binary tree insertion procedure
            if(T==nil){
                T = new Node(X);
            }
            else if(X < T->value){ 
                T->left = insert(X, T->left);
            }
            else if(X > T->value){
                T->right = insert(X, T->right);
            }
            else{
                T->value = X;
            }
            
            //Rebalance code will be put in here later.
            
            return T;
        }
        
        //STUDY THIS! NODE REMOVAL.
        void remove(Value X){root = remove(X, root);}
        
        Node* remove(Value X, Node* &T){
            //Normal binary tree removal procedure
            if(T != nil){
                if(X > T->value){
                    T->right = remove(X, T->right);
                }
                else if(X < T->value){
                    T->left = remove(X, T->left);
                }
                // X == T->Value
                else{
                    if(T->right != nil){
                        Node* x = T->right;
                        while(x->left != nil)
                            x = x->left;
                        T->value = x->value;        //Successor's value
                        T->right = remove(T->value, T->right);
                    }
                    else if(T->left != nil){
                        Node* x = T->left;
                        while(x->right != nil)
                            x = x->right;
                        T->value = x->value;        //Predecessor's value
                        T->left = remove(T->value, T->left);
                    }
                    //*T is external
                    else{
                        delete T;
                        T = nil;
                    }
                }
            }
            //Rebalance code will be put in here later.
            return T;
        }
        
        void okay(){
            okay(root);
        }
        void okay(Node* T){
            //add diagnostic code
            cout << "Height of this tree " << T->height() << endl;
            cout << "Printing root ";
            print_node(root);
            cout << endl;
            
            cout << "Printing root->right ";
            print_node(root->right);
            cout << endl;
            cout << "Printing root->left ";
            print_node(root->left);
            cout << endl;
            cout << "Printing root->left->right ";
            print_node(root->left->right);
            cout <<  endl;
            return;
        }
};

#endif
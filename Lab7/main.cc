//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab7/main.cc
/// @brief Lab 7 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 5/25/2015
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
#include <chrono>   //Use high_resolution_time::now()
#include <fstream>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 2)
    {
        cout << "Error. Usage: ./a.out <wordfile>" << endl;
        return 1;
    }
    
        //Loads words in vector
        vector<string> word_vec;
        string aWord;
        
        fstream inf(argv[1], fstream::in);
        
        if(!inf)
        {
            cout << "Error. File " << argv[1] << " could not be read" << endl;
            return 1;
        }
        
        for(unsigned i = 0; i < 50000; i++){
            inf >> aWord;
            word_vec.push_back(aWord);    
        }
        
        inf.close();
    
    //fstream outf("data.txt", fstream::out | fstream::app);
    fstream outf("data.txt", fstream::out);
    unordered_set<string> hash_tab;
    set<string> tree_set;
    
    for(unsigned j = 5000; j <= 50000; j+=5000)
    {
        chrono::duration<double> timeTreeIns;
        chrono::duration<double> timeHashIns;
        chrono::duration<double> timeTreeFind;
        chrono::duration<double> timeHashFind;
        //10 times per n
        for(unsigned z = 0; z < 10; z++)
        {
            //===========================================
            //Tree insert
            //===========================================
            auto startTime = chrono::high_resolution_clock::now();
            for(unsigned i = 0; i < j; i++){
                tree_set.insert(word_vec[i]);
            }
            auto finTime = chrono::high_resolution_clock::now();
            timeTreeIns += 
            chrono::duration_cast<chrono::duration<double>>(finTime - startTime);
            //get a value in seconds by using time_span.count()
            
            //===========================================
            //Hash insert
            //===========================================
            startTime = chrono::high_resolution_clock::now();
            for(unsigned i = 0; i < j; i++){
                hash_tab.insert(word_vec[i]);
            }
            finTime = chrono::high_resolution_clock::now();
            timeHashIns += 
            chrono::duration_cast<chrono::duration<double>>(finTime - startTime);
            
            //===========================================
            //Tree Find
            //===========================================
            auto it = tree_set.begin();
            startTime = chrono::high_resolution_clock::now();
            for(unsigned i = 0; i < j; i++){
                it = tree_set.find(word_vec[i]);
            }
            finTime = chrono::high_resolution_clock::now();
            timeTreeFind += 
            chrono::duration_cast<chrono::duration<double>>(finTime - startTime);
            
            //===========================================
            //Hash Find
            //===========================================
            auto iter = hash_tab.begin();
            startTime = chrono::high_resolution_clock::now();
            for(unsigned i = 0; i < j; i++){
                iter = hash_tab.find(word_vec[i]);
            }
            finTime = chrono::high_resolution_clock::now();
            timeTreeFind += 
            chrono::duration_cast<chrono::duration<double>>(finTime - startTime);
            
            //Changes order of word vec
            random_shuffle(word_vec.begin(), word_vec.end());
        }
        //Averages
    
        timeTreeIns /= (10);
        timeHashIns /= (10);
        timeTreeFind /= (10);
        timeHashFind /= (10);
        
        //Dump
        outf << j << " " << timeTreeIns.count() << " " << timeHashIns.count();
        outf << " " << timeTreeFind.count() << " " << timeHashFind.count();
        outf << endl;
        
        //Clear set and unordered set
        hash_tab.clear();
        tree_set.clear();
    }
    
    outf.close();
    
    return 0;
}

//http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
                //http://en.cppreference.com/w/cpp/chrono/duration/duration
                //http://www.cplusplus.com/reference/unordered_map/unordered_map/
                //http://www.cplusplus.com/reference/map/map/
                //http://www.cplusplus.com/reference/chrono/
                //http://forums.codeguru.com/showthread.php?422289-reuse-an-fstream-object
                //http://stackoverflow.com/questions/19209156/c-reusing-stdfstream
                //http://www.cplusplus.com/reference/fstream/fstream/open/
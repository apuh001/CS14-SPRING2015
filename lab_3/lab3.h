//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab3/lab3.h
/// @brief Lab 3 Spring 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 4/23/2015
/// @SID: 861162817
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mandar
//  ================== END ASSESSMENT HEADER ===============

#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>

class TwoStackFixed
{
    private:
        T* arr;
        int size; //Stores size of array.
        
        //Stores partition of s1 an s2's current top and max sizes.
        int s1curr, s2curr, s1max, s2max; 
        
    public:
        //Initializes stacks.
        TwoStackFixed(int size, int maxtop)
        {
            assert(size > 0);
            
            //If maxtop > n - 1 then s1 has entire array.
            //Position -1 signifies before first element initialized.
            //If maxtop < 0, then s2 has entire list.
            if (maxtop < 0)
            {
                s1curr = -2; //Signifies nonexistant Stack1
                s1max = -1;
                s2max = 0;
                s2curr = size; //Signifies Stack2 is curr at one after end.
            }
            //Stack1 dominates entire array
            else if(maxtop >= size - 1)
            {
                s1curr = -1; //Signifies Stack1 curr is one before beginning.
                s1max = size - 1;
                s2max = size;
                s2curr = size + 1; //Signifies Stack2 is nonexistant
            }
            //If neither Stack1 nor Stack2 dominates entire array.
            else
            {
                //Max position for s1
                //Remember, s2's first elements starts at size - 1
                s1max = maxtop; 
                s2max = 1 + maxtop; //Max position for s2 is whatever is left.
                s1curr = -1;
                s2curr = size;
            }
            
            this->size = size;
            arr = new T[size];
        }
        
        void pushStack1(T value)
        {
            //If already full or has no space or program terminates.
            //Also if nonexistant, then terminates.
            assert(s1max > 0);
            assert(s1curr < s1max);
            
            s1curr++;
            arr[s1curr] = value;
            display();
            return;
        }
        
        void pushStack2(T value)
        {
            //If already full or has no space or program terminates.
            //Also if nonexistant, then terminates.
            //Be careful, since s2curr must be a HIGHER index, it must be
            //Greater than s2 max.
            assert(s2max < size);
            assert(s2max < s2curr);
            
            //Careful again! s2curr must move DOWN the array to be pushed
            //to the next available spot!
            s2curr--;
            arr[s2curr] = value;
            display();
            return;
        }
        
        T popStack1()
        {
            //Asserts stack1 exists and or is not empty
            assert(!isEmptyStack1());
            
            T temp(arr[s1curr]);
            s1curr--;
            
            return temp;
        }
        
        T popStack2()
        {
            //Asserts stack2 exists and or is not empty
            assert(!isEmptyStack2());
            
            T temp(arr[s2curr]);
            s2curr++;
            
            return temp;
        }
        
        //Nonexistant stacks will return false;
        bool isFullStack1()
        {
            return (s1max == s1curr) ? true : false;
        }
        
        //Nonexistant stacks will return false;
        bool isFullStack2()
        {
            return (s2max == s2curr) ? true : false;
        }
        
        //Counts also for nonexistant stacks.
        bool isEmptyStack1()
        {
            return (s1curr < 0) ? true : false;
        }
        
        //Counts also for nonexistant stacks.
        bool isEmptyStack2()
        {
            return (s2curr >= size) ? true : false;
        }
        
        //If blank, then output whitespace
        void display()
        {
            if(size == 0)
                return;
                
            //Nonexistant stack1
            //Just prints whitespace if any followed by s2's entries
            if(s1curr == -2)
            {
                for(int i = 0; i < size; i++)
                {
                    //When we reach s2's current index, start printing it
                    if(i >= s2curr)
                        cout << arr[i] << " ";
                    //Two spaces, one for emptiness, one for spacing.
                    else
                        cout << "  ";
                }
                cout << endl;
                return;
            }
            //Nonexistant stack2
            //Just prints whitespace if any followed by s1's entries
            if(s2curr == size)
            {
                for(int i = 0; i < size; i++)
                {
                    //When we reach s2's current index, start printing it
                    if(i <= s1curr)
                        cout << arr[i] << " ";
                    //Two spaces, one for emptiness, one for spacing.
                    else
                        cout << "  ";
                }
                cout << endl;
                return;
            }
            
            //Stacks both exist 
            //Prints all of s1's entries first
            for(int i = 0; i <= s1curr; i++)
                cout << arr[i] << " ";
            //Prints out spaces in between if any
            for(int j = s1curr + 1; j < s2curr; j++)
                cout << "  ";    
            //Prints out s2's entries to the end
            for(int k = s2curr; k < size; k++)
                cout << arr[k] << " ";  
            cout << endl;
            return;
        }
};

template <typename T>

class TwoStackOptimal
{
    private:
        T* arr;
        int s1curr, s2curr, maxIndex, size;
        
    public:
        TwoStackOptimal(int size)
        {
            arr = new T[size];
            s1curr = -1;
            s2curr = size;
            maxIndex = -2;
            this->size = size;
        }
        
        void pushFlexStack1(T value)
        {
            //Can't push if full
            assert(maxIndex != s1curr);
            assert(maxIndex != s2curr);
            
            s1curr++;
            arr[s1curr] = value;
            
            if(s1curr + 1 == s2curr)
                maxIndex = s1curr;
            display();
            return;
        }
        
        void pushFlexStack2(T value)
        {
            //Can't push if full
            assert(maxIndex != s1curr);
            assert(maxIndex != s2curr);
            
            s2curr--;
            arr[s2curr] = value;
            
            if(s2curr - 1 == s1curr)
                maxIndex = s2curr;
            display();  
            return;
        }
        
        T popFlexStack1()
        {
            assert(s1curr > -1);
            
            //Resets maxIndex
            if(s1curr == maxIndex || s2curr == maxIndex)
                maxIndex = -2;
            
            T val = arr[s1curr];
            s1curr--;
            
            return val;
        }
        
        T popFlexStack2()
        {
            assert(s2curr < size);
            
            //Resets maxIndex
            if(s1curr == maxIndex || s2curr == maxIndex)
                maxIndex = -2;
            
            T val = arr[s2curr];
            s2curr++;
            
            return val;
        }
        
        bool isFullStack1()
        {
            if(maxIndex == s1curr || maxIndex == s2curr)
                return true;
            return false;
        }
        
        bool isFullStack2()
        {
            if(maxIndex == s1curr || maxIndex == s2curr)
                return true;
            return false;
        }
        
        bool isEmptyStack1()
        {
            if(s1curr == -1)
                return true;
            return false;
        }
        
        bool isEmptyStack2()
        {
            if(s2curr == size)
                return true;
            return false;
        }
        
        void display()
        {
            //Empty prints out spaces.
            //One empty, prints out the occupied one and spaces for empty
            if(isEmptyStack2() && isEmptyStack1())
            {
                for(int i = 0; i < size; i++)
                {
                    cout << "  ";
                }
                cout << endl;
            }
            //Just Stack1 not empty.
            else if(isEmptyStack2() && !isEmptyStack1())
            {
                int i = 0;
                for(; i <= s1curr; i++)
                    cout << arr[i] << " ";
                for(i++; i < size; i++)
                    cout << "  ";
                cout << endl;
            }
            //Just Stack2 is not empty
            else if(!isEmptyStack2() && isEmptyStack1())
            {
                int i = 0;
                for(; i < s2curr; i++)
                    cout << "  ";
                for(; i < size; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            else
            {
                int i = 0;
                for(; i <= s1curr; i++)
                    cout << arr[i] << " ";
                for(; i < s2curr; i++)
                    cout << "  ";
                for(; i < size; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            
            return;
        }
};

template <typename T>

//Helper
void showTowerStates_(int n, stack<T> &A, stack<T> &B, stack <T>&C, 
char src = ' ', char aux = ' ', char dest = ' ')
{
    if(n > 0)
    {
        showTowerStates_(n - 1, A, C, B, src, dest, aux);
        cout << "Moved " << A.top() << " from peg " << src <<" to "<< dest << endl;
        C.push(A.top());
        A.pop();
        showTowerStates_(n - 1, B, A, C, aux, src, dest);
    }
}

template <typename T>

//A B C are source aux and destination stacks.
//Output should have format: Moved [VALUE] from peg A to B
void showTowerStates(int n, stack<T> &A, stack<T> &B, stack <T>&C)
{
    showTowerStates_(n, A, B, C, 'A', 'B', 'C');
}
    
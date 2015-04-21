

using namespace std;

template <typename T>

class TwoStackFixed
{
    private:
        T* arr;
        int sz; //Stores size of array.
        
        //Stores partition of s1 an s2's current top and max sizes.
        int s1curr, s2curr, s1max, s2max; 
        
    public:
        //Initializes stacks.
        TwoStackFixed(int size, int maxtop)
        {
            //If maxtop > n - 1 then s1 has entire array.
            //Position -1 signifies before first element initialized.
            //If maxtop < 0, then s2 has entire list.
            if (maxtop < 0)
            {
                s1curr = -2; //Signifies nonexistant Stack1
                s1max = maxtop;
                s2max = 0;
                s2curr = size; //Signifies Stack2 is curr at one after end.
            }
            else if(maxtop >= size - 1)
            {
                s1curr = -1; //Signifies Stack1 curr is one before end.
                s1max = size - 1;
                s2max = size;
                s2curr = size + 1; //Signifies Stack2 is nonexistant
            }
            //If neither Stack1 nor Stack2 dominates entire array.
            else
            {
                
                s1max = maxtop; //Max position for s1
                //Remember, s2's first elements starts at size - 1
                s2max = 1 + maxtop //Max position for s2 is whatever is left.
                s1curr = 0;
            }
            
            sz = size;
            arr = new T[size];
            
            
        }
        
        void pushStack1(T value)
        {
            //If already full or has no space or program terminates.
            assert(s1curr == s1max);
            assert(s1max < 0);
           
        }
        
        void pushStack2(T value)
        {
            
        }
        
        T popStack1()
        {
            
        }
        
        T popStack2()
        {
            
        }
        
        bool isFullStack1()
        {
            return (s1max == s1curr) ? true : false;
        }
        
        bool isFullStack2()
        {
            return (s2max == s2curr) ? true : false;
        }
        
        bool isEmptyStack1()
        {
            return (s1curr <= 0) ? true : false;
        }
        
        bool isEmptyStack2()
        {
            return (s2curr >= size) ? true : false;
        }
        
        //If blank, then output whitespace
        void display()
        {
            
        }
}
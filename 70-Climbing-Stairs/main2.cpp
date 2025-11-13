#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        memo = new vector<int>(n + 1, -1);
        return climbStairs_int(n);
    }

    int climbStairs_int(int n) {
        //cout << n << endl;
        if (n <= 2) return n;
        
        if ((*memo)[n] != -1) {
            return (*memo)[n];
        }
        int result = climbStairs_int(n-1) + climbStairs_int(n-2);
        (*memo)[n] = result;
        return (*memo)[n];
    }



private:
    /*
      We can use 
        vector<int>* memo;

        in both cases the actuall array of the vector is allocated on 
the heap.
        but when using 
        vector<int> memo;
        we allocate the object itself on the stack, and only the array 
is on the heap.

        whereas when using
        vector<int>* memo;
        we allocate both the object and its actuall array on the heap.
    */
    vector<int>* memo;
};



int main()
{
    Solution sol;

    int result = sol.climbStairs(5);

    cout << "result: " << result << endl;
}


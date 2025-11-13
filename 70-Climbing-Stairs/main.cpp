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
        (*memo)[1] = 1;
        (*memo)[2] = 2;

        
        for (int i = 3; i <= n; i++) {
            (*memo)[i] = (*memo)[i - 1] + (*memo)[i - 2];
        }

        return (*memo)[n];
    }



private:
    vector<int>* memo;
};



int main()
{
    Solution sol;

    int result = sol.climbStairs(4);

    cout << "result: " << result << endl;
}


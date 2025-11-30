#include <vector>
#include <algorithm>
#include <iostream>
#include <climits> 

using namespace std;


class Solution {
public:

    vector<int> memo;

    /* chatGpt - change function name to be dfs() */
    int coinChange_int(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return -1;
        }

        /*
        chatGpt:
        change -3 to be some const like:
        const int UNVISITED = -2;
        and then
        if (memo[amount] != UNVISITED) return memo[amount];
        */
        if (memo[amount] != -3) { 
            return memo[amount];
        }

        int result = INT_MAX;
        for (int coin : coins) {

            /*
            chatGpt:
            add condition 
            if (coin > amount) continue;
            to spare redundant calls 
            */
            int curr = coinChange_int(coins, amount - coin);
            if (curr >= 0) {
                result = min(result, 1 + curr);
            }
            
        }

        if (result == INT_MAX) {
            result = -1;
        }
        memo[amount] = result;

        return result;
    }


    int coinChange(vector<int>& coins, int amount) {

        memo = vector<int>(amount+1, -3);
        return coinChange_int(coins, amount);
    }

};

int main()
{
    Solution sol;

    vector<int> coins = {1,2,5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);

    cout << "result: " << result << endl;
}


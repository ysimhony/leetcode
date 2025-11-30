#include <vector>
#include <algorithm>
#include <iostream>
#include <climits> 

using namespace std;


class Solution {
public:

    vector<int> memo;

    int coinChange(vector<int>& coins, int amount) {

        memo = vector<int>(amount+1, INT_MAX);
        memo[0] = 0;

        for (int i = 0;i <= amount;i++) {

            for (int coin : coins) {
                if(coin > 10001) {
                    continue;
                }
                if (i + coin > amount) {
                    continue;
                }

                /*
                chatGpt:
                move this condition before the loop of the coins
                */
                if (memo[i] == INT_MAX) {
                    continue;
                }
                memo[i + coin] = min(memo[i + coin], memo[i] + 1);
            }
        }

        return (memo[amount]==INT_MAX)?-1:memo[amount];
        
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


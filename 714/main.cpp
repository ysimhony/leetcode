#include <iostream>
#include <vector>

using namespace std;
#include <new>

class Solution {
public:

    int maxProfitVar = 0;
    int findMaxProfit(vector<int> prices, int fee) {
        int currProfit = 0;

        findMaxProfitInt(prices, fee, 0, false, currProfit);

        return maxProfitVar;
    }

    void findMaxProfitInt(vector<int> prices, int fee, int index, bool holding, int currProfit) {

        if (index == prices.size()) {


            cout << "currProfit: " << currProfit << endl;
            maxProfitVar = max(maxProfitVar, currProfit);
            return;
        }


        if (holding) {
            
            // keep - dont sell
            findMaxProfitInt(prices, fee, index + 1, true, currProfit);
            
            // sell
            
            findMaxProfitInt(prices, fee, index + 1, false, currProfit + prices[index] - fee);

        }
        else {
            
            // keep - dont buy
            findMaxProfitInt(prices, fee, index + 1, false, currProfit);
            
            // buy
            
            findMaxProfitInt(prices, fee, index + 1, true, currProfit - prices[index]);
        }
    }

};



int main()
{
    Solution sol;
    vector<int> prices = { 2, 4, 6 };
    int maxProfit = sol.findMaxProfit(prices, 1);
    cout << "maxProfit: " << maxProfit << endl;

}


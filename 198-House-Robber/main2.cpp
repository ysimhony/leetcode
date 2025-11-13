#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob_int(vector<int>& nums, int index, vector<int>& memo) {

        if (index == 0) {
            return nums[0];
        }

        if (index == 1) {
            return (max(nums[0], nums[1]));
        }

        if (memo[index] != -1) {
            return memo[index];
        }
        int result = max(rob_int(nums, index - 1, memo), rob_int(nums, index - 2, memo) + nums[index]);

        memo[index] = result;
        return result;

    }

    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return rob_int(nums, nums.size() - 1, memo);
    }


private:
    vector<int> memo;
};



int main()
{
    Solution sol;
    vector<int> nums = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    int result = sol.rob(nums);

    cout << "result: " << result << endl;
}


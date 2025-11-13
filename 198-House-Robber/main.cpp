#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }    
        memo = vector<int>(nums.size(), -1);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);

        for (int i=2; i<nums.size(); i++) {
            memo[i] = max(memo[i-1], memo[i-2] + nums[i]);
        }
        return memo[nums.size()-1];
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


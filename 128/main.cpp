#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int prev = 0;
        int curr;
        int result = 0;
        int n = nums.size();
        int count;

        while (prev < n) {
            
            curr = prev + 1;
            count = 1;
            while (curr < n) {
                if (nums[curr] - 1 == nums[curr-1]) {
                    count++;
                }
                else if (nums[curr] > nums[curr-1] + 1) {
                    break;
                }
                
                curr++;
            }

            result = max(result, count);
            prev = curr;
        }

        result = max(result, count);
        return result;
    }
};



int main()
{
    Solution sol;

    vector<int> nums = {100,4,200,1,3,2};
    int result = sol.longestConsecutive(nums);

    cout << "result: " << result << endl;
}


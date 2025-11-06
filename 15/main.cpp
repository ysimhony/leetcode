#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int i, j, k;
        int n = nums.size();

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        i = 0;
        while (i<nums.size() && nums[i] <= 0) {
            
            while (i > 0 && i<nums.size() && nums[i] == nums[i - 1] ) {
                
                i++;
            }

            if (i >= nums.size()){break;}
            j = i + 1;
            k = n - 1;

            while (j < k) {
                
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    
                    result.push_back({ nums[i], nums[j], nums[k] });
                    
                    j++;
                    
                    while (j < k && nums[j] == nums[j - 1]) {
                        
                        j++;
                    }
                }
            }
            
            i++;
            
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> result = sol.threeSum(nums);
}


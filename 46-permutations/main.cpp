#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void permute_int(vector<int>& nums, int index, vector<int>& curr, unordered_set<int>& used, vector<vector<int>>& result) {
        

        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used.find(i) != used.end()) {
                continue;
            }

            used.insert(i);
            curr.push_back(nums[i]);
            permute_int(nums, index + 1, curr, used, result);
            curr.pop_back();
            used.erase(i);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        unordered_set<int> used;
        permute_int(nums, 0, curr, used, result);
        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1,3,2};
    vector<vector<int>> result = sol.permute(nums);

    for (auto it_vec = result.begin(); it_vec != result.end(); ++it_vec) {
        cout << "{" ;
        for (auto it = (*it_vec).begin(); it != (*it_vec).end(); ++it) {
            cout << *it;
            if (next(it) != (*it_vec).end()) {
                cout << " " ;
            }
        }
        cout << "}";
        if (next(it_vec) != result.end() ){
            cout << ",";
        }
    }
    cout << endl;
}


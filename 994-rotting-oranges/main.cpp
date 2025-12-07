#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int freshCount = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        queue<pair<pair<int, int>, int>> q;
        int time = 0;

        for (int i = 0;i < m;i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    
                    q.push(make_pair(make_pair(i, j), time));
                    grid[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }        
        
        while (!q.empty()) {
            pair<pair<int, int>, int> elem = q.front();
            q.pop();

            pair<int, int> point = elem.first;
            time = elem.second;

            //cout << "x: " << point.first << " y: " << point.second << " time: " << time << endl;
            for (auto direction : directions) {
                int new_x = point.first + direction[0];
                int new_y = point.second + direction[1];
                if ((new_x < 0) || (new_x >= m) || (new_y < 0) || (new_y >= n)) {
                    continue;
                }
                if (grid[new_x][new_y] == 1) {

                    grid[new_x][new_y] = 0;
                    freshCount--;
                    q.push(make_pair(make_pair(new_x, new_y), time + 1));
                }
            }
        }

        if (freshCount > 0) {
            return -1;
        }

        return time;

    }
};


int main()
{
    Solution sol;

    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int result = sol.orangesRotting(grid);
    cout << "result: " << result << endl;

    grid = {{2,1,1},{0,1,1},{1,0,1}};
    result = sol.orangesRotting(grid);
    cout << "result: " << result << endl;



}


#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
 
class Solution {
private:
int perimeter;
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            perimeter ++;
            return;
        }
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }       
        return perimeter;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

    Solution solution;

    cout << solution.islandPerimeter(grid) << endl;

    vector<int>::iterator it;
    vector<vector<int>>::iterator iter;
    vector<int> vec_tmp;
    for (iter = grid.begin(); iter != grid.end(); iter++)
    {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
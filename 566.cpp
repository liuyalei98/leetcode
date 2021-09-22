#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat;

        vector<vector<int>> ans(r, vector<int> (c));
        for(int i = 0; i < m * n; i++) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }

        return ans;
    }
};
 
int main()
{
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 2;
    int c = 4;
    Solution solution;

    vector<vector<int>> result = solution.matrixReshape(mat, r, c);

    vector<int>::iterator it;
    vector<vector<int>>::iterator iter;
    vector<int> vec_tmp;
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
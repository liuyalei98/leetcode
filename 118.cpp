#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        dp[0].push_back(1);
        for(int i = 1; i < numRows; i++) {
            dp[i].push_back(1);
            for(int j = 1; j < i; j++) {
                dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            dp[i].push_back(1);
        }

        return dp;
    }
};
 
int main()
{
    int numRows = 5;
    Solution solution;

    vector<vector<int>> result = solution.generate(numRows);

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
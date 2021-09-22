#include <iostream>
#include <vector>

using namespace std;
 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int dp[prices.size()][2];
//         dp[0][0] = -prices[0];
//         dp[0][1] = 0;
//         for(int i = 1; i < prices.size(); i++) {
//             dp[i][0] = max(dp[i-1][0], -prices[i]);  //121
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);  //122
//             dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
//         }
//         return dp[prices.size() - 1][1];
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int max = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] > prices[i - 1]) max += prices[i] - prices[i - 1]; //122
//         }
//         return max;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }
        return dp[prices.size() - 1][1];
    }
};
 
int main()
{
    vector<int> nums = {7,6,4,3,1,9};
    Solution solution;

    cout << solution.maxProfit(nums) << endl;

    return 0;
}
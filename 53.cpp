#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            ans += nums[i];
            if (nums[i] > ans) ans = nums[i];
            if (max < ans) max = ans;
        }
        return max;
        
    }
};
 
int main()
{
    vector<int> nums = {-2,1};
    Solution solution;

    cout << solution.maxSubArray(nums) << endl;

    return 0;
}
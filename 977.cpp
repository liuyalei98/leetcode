#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        for (int n = nums.size() - 1; n >= 0; n--) {
            int left_2 = nums[left] * nums[left];
            int right_2 = nums[right] * nums[right];
            if (left_2 >= right_2) {
                ans[n] = left_2;
                left ++;
            }
            else {
                ans[n] = right_2;
                right --;
            }
        }
        return ans;
    }
};
 
int main()
{
    vector<int> nums = {0,3,10};
    Solution solution;

    vector<int> res = solution.sortedSquares(nums);

    vector<int>::iterator it;
    for(it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}


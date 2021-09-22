#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
 
int main()
{
    vector<int> nums = {1};
    int k = 3;
    Solution solution;

    solution.rotate(nums, k);

    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}


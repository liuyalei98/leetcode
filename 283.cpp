#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0;
        int low = 0;
        while (fast < nums.size()) {
            if (nums[fast] != 0 ) {
                nums[low] = nums[fast];
                low ++;
            }
            fast ++;
        }
        while (low < nums.size()) {
            nums[low] = 0;
            low ++;
        }
    }
};
 
int main()
{
    vector<int> nums = {0,1,0,3,12};
    Solution solution;

    solution.moveZeroes(nums);

    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}


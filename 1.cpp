#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    Solution solution;

    vector<int> result = solution.twoSum(nums, target);

    vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
    for(it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
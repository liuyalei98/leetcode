#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> m;
        vector<int>::iterator it;
        for (it = nums1.begin(); it != nums1.end(); it++) {
            m[*it] ++;
        }
        for (it = nums2.begin(); it != nums2.end(); it++) {
            if (m[*it] > 0) {
                res.push_back(*it);
                m[*it] --;
            }
        }
        return res;
    }
};
 
int main()
{
    vector<int> nums1 = {2, 2};
    vector<int> nums2 = {1, 2, 2, 1};
    Solution solution;

    vector<int> result = solution.intersect(nums1, nums2);

    vector<int>::iterator it;
    for(it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
#include <iostream>
#include<vector>

using namespace std;
 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        vector<int>::iterator p, q, e;      

        if (m == 0) {
            p = nums1.begin();
            q = nums2.begin();
            for(int i = 0; i < n ; i++) {
                *p = *q;
                p ++;
                q ++;
            }
            return;
        }

        else {
            p = nums1.begin() + m - 1;
            q = nums2.begin() + n - 1;
            e = nums1.begin() + m + n - 1;

            if (*q < *p) {
                *e = *p;
                m --;
                merge(nums1, m, nums2, n);
            }
            else {
                *e = *q;
                n --;
                merge(nums1, m, nums2, n);
            }
            e --;
        }
    }
};
 
int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    Solution solution;

    solution.merge(nums1, m, nums2, n);

    vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
    for(it = nums1.begin(); it != nums1.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}


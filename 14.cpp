#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.front().length();
        string s;
        for (int i = 1; i <= n; i ++) {
            bool f = strs.front().compare(0, i, strs.back(), 0, i);  //比较从0开始的第i个字符是否相等
            if (!f) {
                s = strs.front().substr(0, i);
            }
            else break;
        }
        return s;
    }
};

int main()
{
    vector<string> strs = {"a", "flow", "flight"};
    Solution solution;

    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}
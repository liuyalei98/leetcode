#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

void printMap(map<char, int> m)
{
    map<char, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << "--" << it->second << endl;
    }
    cout << endl;
}

class Solution {
public:
    //滑动窗口
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char, int> m;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (m[s[right]] == 0) {
                m[s[right]] = right + 1;               
            }
            else {
                left = max(m[s[right]], left);
                m[s[right]] = right + 1;
            }  
            right ++;
            ans = max(ans, right - left);    
        }
        return ans;
    }
};

int main()
{
    string s = {"aabaab!bb"};
    Solution solution;

    cout << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}
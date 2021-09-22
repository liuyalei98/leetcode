#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;
 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())   return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] !=  t[i]) return false;
        }
        return true;
    }
};
 
int main()
{
    string s = {"ab"};
    string t = {"ba"};
    Solution solution;

    cout << solution.isAnagram(s, t) << endl;

    return 0;
}
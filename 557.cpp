#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        int i, j;
        for (i = 0, j = 0; i < s.size(); i ++) {
            if (s[i] == ' ') {
                while (!st.empty()) {
                    s[j] = st.top();
                    st.pop();
                    j ++;
                }
                j = i + 1;
            }
            else st.push(s[i]);
        }
        while (!st.empty()) {
            s[j] = st.top();
            st.pop();
            j ++;
        }
        return s;
    }
};

int main()
{
    string s = {"I love leetcode"};
    Solution solution;

    cout << solution.reverseWords(s) << endl;

    return 0;
}
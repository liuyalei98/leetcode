#include <iostream>
#include <map>
#include <string.h>

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
    int firstUniqChar(string s) {
        map<char, int> m;
        for( int i = 0; i < s.size(); i++) {
            m[s[i]] ++;
        }
        for (int i = 0; i < s.size(); i++) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};
 
int main()
{
    string s = {"loveleetcode"};
    Solution solution;

    cout << solution.firstUniqChar(s) << endl;

    return 0;
}
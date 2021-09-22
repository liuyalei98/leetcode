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
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        map<char, int> m;
        for( int i = 0; i < ransomNote.size(); i++) {
            m[ransomNote[i]] ++;
        }
        for( int i = 0; i < magazine.size(); i++) {
            if (m[magazine[i]] > 0) {
                m[magazine[i]] --;
            }
        }
        map<char, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second != 0) return false;
        }
        return true;
    }
};
 
int main()
{
    string ransomNote = {"abb"};
    string magazine = {"aab"};
    Solution solution;

    cout << solution.canConstruct(ransomNote, magazine) << endl;

    return 0;
}
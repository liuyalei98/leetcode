#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int res = 0;
        int last = 0;
        while(s.empty() != true){
            char c = s.back();
            int ans = roman[c];
            if (ans >= last) res += ans;
            else res -= ans;
            last = ans;
            s.pop_back();
        }
        return res;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution solution;

    cout << solution.romanToInt(s) << endl;

    return 0;
}
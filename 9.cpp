#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long ans = 0;
        int temp = x;
        while (temp != 0) {
            ans = ans * 10 + temp % 10;
            temp = temp / 10;
        }
        if (ans == x) return true;
        return false;
    }
};

int main()
{
    int x = 998765432;
    Solution solution;

    cout << solution.isPalindrome(x) << endl;

    return 0;
}
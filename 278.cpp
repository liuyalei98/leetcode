#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left != right) {
            int middle = left + (right - left) / 2;
            if (!isBadVersion(middle)) left = middle + 1;
            else right = middle;
        }
        return left;
    }

private:
    int bad = 2;
    bool isBadVersion(int version) {
        if (version >= bad) return true;
        else return false;
    }
};

int main()
{
    int n = 5;

    Solution solution;

    cout << solution.firstBadVersion(n) << endl;

    return 0;
}
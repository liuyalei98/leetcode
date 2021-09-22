#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> numRows(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            for(int j = rowIndex; j >= 0; j--) {
                if (j == 0 || j == i) numRows[j] = 1;
                else numRows[j] = numRows[j] + numRows[j - 1];
            }
        }
        return numRows;
    }
};
 
int main()
{
    int rowIndex = 4;
    Solution solution;

    vector<int> result = solution.getRow(rowIndex);

    vector<int>::iterator it;
    for(it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
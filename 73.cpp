#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r0 = false, c0 = false;
        for (int i = 0; i < matrix[0].size(); i++)
            if (matrix[0][i] == 0) r0 = true;
        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0) c0 = true;
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[i].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (r0) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        if (c0) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
 
int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    Solution solution;

    solution.setZeroes(matrix);

    vector<int>::iterator it;
    vector<vector<int>>::iterator iter;
    vector<int> vec_tmp;
    for (iter = matrix.begin(); iter != matrix.end(); iter++)
    {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
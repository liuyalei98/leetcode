#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int columns[9][9];
        int boxes[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(boxes, 0, sizeof(boxes));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if ( c != '.') {
                    int a = c - '0' - 1;
                    rows[i][a] ++;
                    columns[j][a] ++;
                    boxes[i/3][j/3][a] ++;
                    if (rows[i][a] > 1 || columns[j][a] > 1 || boxes[i/3][j/3][a] > 1)
                        return false;
                }
            }
        }

        return true;
    }
};
 
int main()
{
    vector<vector<char>> board = {{'8','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    Solution solution;

    cout << solution.isValidSudoku(board) << endl;

    vector<char>::iterator it;
    vector<vector<char>>::iterator iter;
    vector<char> vec_tmp;
    for (iter = board.begin(); iter != board.end(); iter++)
    {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
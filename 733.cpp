#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
 
class Solution {
private:
int oColor;
int nColor;
public:
    void dfs(vector<vector<int>>& image, int i, int j) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != oColor) return;
        image[i][j] = nColor;
        dfs(image, i - 1, j);
        dfs(image, i + 1, j);
        dfs(image, i, j + 1);
        dfs(image, i, j - 1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oColor = image[sr][sc];
        if (oColor == newColor) return image;
        nColor = newColor;
        dfs(image, sr, sc);
        return image;
    }
};

int main()
{
    vector<vector<int>> image = {{0,0,0},{0,0,0}};
    int sr = 0;
    int sc = 0;
    int newColor = 2;

    Solution solution;

    vector<vector<int>> res = solution.floodFill(image, sr, sc, newColor);

    vector<int>::iterator it;
    vector<vector<int>>::iterator iter;
    vector<int> vec_tmp;
    for (iter = res.begin(); iter != res.end(); iter++)
    {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
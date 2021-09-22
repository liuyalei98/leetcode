#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(5);
    root->left = t1;
    root->right = t2;
    t2->left = t3;
    t2->right = t4;

    Solution solution;

    vector<vector<int>> result = solution.levelOrder(root);

    vector<int>::iterator it;
    vector<vector<int>>::iterator iter;
    vector<int> vec_tmp;
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}


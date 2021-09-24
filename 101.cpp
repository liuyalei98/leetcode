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
    bool isSameTree(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr || right == nullptr) return false;
        else if (left->val != right->val) return false;
        return isSameTree(left->left, right->right) && isSameTree(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (isSameTree(left, right)) return true;
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(2);
    root->left = t1;
    root->right = t2;
    //t1->right = t3;
    //t2->left = t4;

    Solution solution;

    cout << solution.isSymmetric(root) << endl;

    return 0;
}


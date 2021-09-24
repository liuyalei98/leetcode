#include <iostream>
#include <vector>
#include <stack>

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
    //递归
    void preorder(TreeNode* root, vector<int> &res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res = {};
        preorder(root, res);
        return res;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        return root1;
    }
};

int main()
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *t11 = new TreeNode(2);
    TreeNode *t12 = new TreeNode(3);
    root1->left = t11;
    t11->right = t12;

    TreeNode *root2 = new TreeNode(1);
    TreeNode *t21 = new TreeNode(2);
    TreeNode *t22 = new TreeNode(3);
    root2->left = t21;
    root2->right = t22;

    Solution solution;

    TreeNode *result = solution.mergeTrees(root1, root2);
    vector<int> r = solution.preorderTraversal(result);

    vector<int>::iterator it;
    for (it = r.begin(); it != r.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}


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
    // //递归
    // void preorder(TreeNode* root, vector<int> &res) {
    //     if (root == nullptr) return;
    //     res.push_back(root->val);
    //     preorder(root->left, res);
    //     preorder(root->right, res);
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     preorder(root, res);
    //     return res;
    // }

    //迭代
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res = {};
        if (root == nullptr) return res;

        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                st.emplace(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    root->left = t1;
    t1->right = t2;

    Solution solution;

    vector<int> result = solution.preorderTraversal(root);

    vector<int>::iterator it;
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}


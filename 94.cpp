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
    // void inorder(TreeNode* root, vector<int> &res) {
    //     if (root == nullptr) return;
    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     inorder(root, res);
    //     return res;
    // }

    //迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = {};
        if (root == nullptr) return res;

        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.emplace(node);
                node = node->left;
            }
            node = st.top();
            res.emplace_back(node->val);
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
    root->right = t1;
    t1->left = t2;

    Solution solution;

    vector<int> result = solution.inorderTraversal(root);

    vector<int>::iterator it;
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}


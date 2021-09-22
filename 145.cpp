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
    // //递归
    // void postorder(TreeNode* root, vector<int> &res) {
    //     if (root == nullptr) return;
    //     postorder(root->left, res);
    //     postorder(root->right, res);
    //     res.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     postorder(root, res);
    //     return res;
    // }

    //迭代
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res = {};
        if (root == nullptr) return res;

        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                st.emplace(node);
                node = node->right;
            }
            node = st.top();
            st.pop();
            node = node->left;
        }
        reverse(res.begin(), res.end());
        return res;
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

    vector<int> result = solution.postorderTraversal(root);

    vector<int>::iterator it;
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}


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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        if (root != nullptr) q.emplace(root);
        while (!q.empty()) {
            depth ++;
            int levelLenth = q.size();
            for (int i = 0; i < levelLenth; i++) {
                TreeNode* node = q.front();
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
                q.pop();
            }
        }
        return depth;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(6);
    root->left = t1;
    root->right = t2;
    //t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t5->left = t3;

    Solution solution;

    cout << solution.maxDepth(root) << endl;

    return 0;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root != nullptr) 
        {
            queue<TreeNode *> queueNode;
            queueNode.push(root);
            while (!queueNode.empty())
            {
                auto qSize = queueNode.size();
                int rightMost = -1;
                for (int i = 0; i < qSize; i++)
                {
                    TreeNode *node = queueNode.front();
                    queueNode.pop();
                    rightMost = node->val;
                    if (node->left) { queueNode.push(node->left); }
                    if (node->right) { queueNode.push(node->right); }
                }
                res.push_back(rightMost);
            }
        }
        return res;
    }
};

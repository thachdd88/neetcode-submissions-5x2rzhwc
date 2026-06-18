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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rootList;
        queue<pair<int, TreeNode *>>queueNode;
        queueNode.emplace(0, root);
        while (!queueNode.empty())
        {
            auto node = queueNode.front();
            queueNode.pop();
            if (node.second != nullptr)
            {
                if (node.first+1 > rootList.size()) { rootList.push_back(vector<int>()); }
                rootList[node.first].push_back(node.second->val);
                if (node.second->left) {queueNode.emplace(node.first+1, node.second->left);}
                if (node.second->right) {queueNode.emplace(node.first+1, node.second->right);}
            }
        }
        return rootList; 
    }
};

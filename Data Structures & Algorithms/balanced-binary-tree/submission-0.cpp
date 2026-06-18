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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        depthSearch(root, balanced);
        return balanced;
    }
    int depthSearch(TreeNode *root, bool &balanced)
    {
        if (root == nullptr) { return 0; }
        else
        {
            int hL = depthSearch(root->left, balanced);
            int hR = depthSearch(root->right, balanced);
            balanced = balanced && (abs(hL-hR) <= 1);
            return max(hL, hR) + 1;
        }
    }
};

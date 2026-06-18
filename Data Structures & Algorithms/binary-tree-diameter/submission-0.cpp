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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        depthSearch(root, max);
        return max;
    }
    int depthSearch(TreeNode *root, int &diameter)
    {
        if (root == nullptr) { return 0; }
        else 
        {
            int diaMax = 0;
            int depthLeft = depthSearch(root->left, diaMax);
            diameter = max(diameter, diaMax);
            int depthRight = depthSearch(root->right, diaMax);
            diameter = max(diameter, diaMax);
            diameter = max(diameter, depthLeft+depthRight);
            return max(depthLeft, depthRight)+1;
        }
    }
};

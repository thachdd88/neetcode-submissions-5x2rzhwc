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
    int maxPathSum(TreeNode* root) 
    {
        findPathSum(root);
        return maxVal;
    }
    int findPathSum(TreeNode* root) 
    {
        if (root == nullptr) { return -1000000; }
        int leftVal = findPathSum(root->left);
        int rightVal = findPathSum(root->right);

        maxVal = max(maxVal, root->val);
        maxVal = max(maxVal, leftVal);
        maxVal = max(maxVal, rightVal);
        maxVal = max(maxVal, leftVal + root->val);
        maxVal = max(maxVal, root->val + rightVal);
        maxVal = max(maxVal, leftVal + root->val + rightVal);

        return max(root->val, max(leftVal + root->val, root->val + rightVal));
    }

private:
    int maxVal{-1000000};
};

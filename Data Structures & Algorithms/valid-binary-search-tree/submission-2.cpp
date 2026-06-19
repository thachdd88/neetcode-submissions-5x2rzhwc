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
    bool isValidBST(TreeNode* root) {
        if (!root) { return true; }
        else
        {
            int minVal, maxVal;
            return isValidBST(root, minVal, maxVal);
        }
    }
    bool isValidBST(TreeNode *root, int &minVal, int &maxVal)
    {
        int minLeft, maxLeft;
        if (root->left == nullptr) { minLeft = root->val; } 
        else if (!isValidBST(root->left, minLeft, maxLeft)) { return false; }
        else
        {
            if (maxLeft >= root->val) { return false; }
        }
        minVal = minLeft;

        int minRight, maxRight;
        if (root->right == nullptr) { maxRight = root->val; } 
        else if (!isValidBST(root->right, minRight, maxRight)) { return false; }
        else
        {
            if (minRight <= root->val) { return false; }
        }
        maxVal = maxRight;
        return true;
    }
};

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
    int kthSmallest(TreeNode* root, int k) {
        int ith = k;
        return searchLeftMost(root, ith);
    }
    int searchLeftMost(TreeNode *root, int &ith)
    {
        if (root == nullptr) { return -1; }
        
        int value = searchLeftMost(root->left, ith);
        if (ith == 0) { return value; }    
        else
        {
            ith--; 
            if (ith == 0) { return root->val; }    
            return searchLeftMost(root->right, ith);
        } 
    }
};

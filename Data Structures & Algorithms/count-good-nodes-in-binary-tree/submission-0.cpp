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
    int goodNodes(TreeNode* root) {
        int count{0};
        if (root)
        {
            int maxVal = root->val;
            count = countGood(root->left, maxVal)+countGood(root->right, maxVal)+1;
        }
        return count;
    }

    int countGood(TreeNode* root, int maxVal)
    {
        if (root)
        {
            int count = 0;
            if (root->val >= maxVal) { count = 1; maxVal=root->val; }
            count += countGood(root->left, maxVal) + 
                    countGood(root->right, maxVal);
            return count;
        }
        else { return 0; }
    }
};

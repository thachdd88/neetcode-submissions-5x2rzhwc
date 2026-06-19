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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        preorder_ = preorder;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap_[inorder[i]] = i;
        }
        
        return buildSub(0, 0, inorder.size());
    }
    TreeNode *buildSub(int rootIdx, int inL, int inR)
    {
        TreeNode *root = new TreeNode(preorder_[rootIdx]);
        int inIdx = inMap_[preorder_[rootIdx]];
        printf("Root: %d -> %d\n", root->val, inIdx);
        
        int leftSub{-1};
        for (int i = rootIdx+1; i < preorder_.size(); i++)
        {
            int leftIdx = inMap_[preorder_[i]];
            if ((leftIdx >= inL) && (leftIdx < inIdx))
            {
                leftSub = i;
                break;
            }
        }
        root->left = (leftSub>=0)? buildSub(leftSub, inL, inIdx) : nullptr; 

        int rightSub{-1};
        for (int i = inIdx+1; i < preorder_.size(); i++)
        {
            int rightIdx = inMap_[preorder_[i]];
            if ((rightIdx < inR) && (inIdx < rightIdx))
            {
                rightSub = i;
                break;
            }
        }
        root->right = (rightSub>=0)? buildSub(rightSub, inIdx, inR) : nullptr; 
                
        printf("L: %d, R: %d\n", leftSub, rightSub);

        return root;
    }

private:
    map<int, int> inMap_{};
    vector<int> preorder_;
};

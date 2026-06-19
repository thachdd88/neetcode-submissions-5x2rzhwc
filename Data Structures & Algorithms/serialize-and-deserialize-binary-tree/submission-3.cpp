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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        queue<TreeNode*> qTree;
        qTree.push(root);
        stringstream ss;
        while (!qTree.empty())
        {
            int n = qTree.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = qTree.front();
                qTree.pop();
                if (node)
                {
                    ss << node->val << ',';
                    qTree.push(node->left);
                    qTree.push(node->right);
                }
                else { ss << "#,"; }
            }
        }
        string res = ss.str();        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<TreeNode*> nodeList;
        int sIdx = 0;
        int idx = data.find(',', sIdx);
        while (idx != string::npos)
        {
            string sub = data.substr(sIdx, idx-sIdx);
            try
            {
                int val = stoi(sub);
                nodeList.push_back(new TreeNode(val));                
            }
            catch (const std::exception &ex) { nodeList.push_back(nullptr); }
            sIdx = idx+1;
            idx = data.find(',', sIdx);
        }
        int child = 0;
        for (int i = 0; i < nodeList.size(); i++)
        {
            TreeNode *node = nodeList[i];
            if (!node) { continue; }
            if (++child < nodeList.size()) { node->left = nodeList[child]; }
            if (++child < nodeList.size()) { node->right = nodeList[child]; }
        }
        return (nodeList.empty())? nullptr : nodeList[0];
    }
};

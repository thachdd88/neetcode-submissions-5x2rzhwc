class PrefixTree 
{
    struct TreeNode
    {
        int key;        
        map<int, TreeNode *> nextKeys;   
        bool hasEnd;    

        TreeNode(int key)
        : key(key), hasEnd(false) {}
    };
public:
    PrefixTree() : root(new TreeNode(-1)) {}
    
    void insert(string word) 
    {
        TreeNode *iter = root;
        for (int i = 0; i < word.length(); i++)
        {
            int key = word[i] - 'a';
            if (iter->nextKeys[key] == nullptr)
            {
                iter->nextKeys[key] = new TreeNode(key);
            }
            iter = iter->nextKeys[key];
        }
        iter->hasEnd = true;
    }
    
    bool search(string word) 
    {
        bool found = true;
        TreeNode *iter = root;
        for (int i = 0; found && i < word.length(); i++)
        {
            int key = word[i] - 'a';
            if (iter->nextKeys.find(key) == iter->nextKeys.end()) { found = false; }
            else { iter = iter->nextKeys[key]; }
        }
        return found && iter->hasEnd;
    }
    
    bool startsWith(string prefix) 
    {      
        bool found = true;
        TreeNode *iter = root;
        for (int i = 0; found && i < prefix.length(); i++)
        {
            int key = prefix[i] - 'a';
            if (iter->nextKeys.find(key) == iter->nextKeys.end()) { found = false; }
            else { iter = iter->nextKeys[key]; }
        }
        return found;
    }

private:
    TreeNode *root;
};

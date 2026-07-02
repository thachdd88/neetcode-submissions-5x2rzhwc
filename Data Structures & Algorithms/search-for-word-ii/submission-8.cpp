class Solution {
    struct TrieNode
    {
        int key;
        map<int, TrieNode*> nextKeys;
        int wIndex;
        TrieNode(int key) : key(key), nextKeys{}, wIndex(-1) {}
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode(-1);
        finalList.clear();
        for (int i = 0; i < words.size(); i++) { insertWord(words[i], i); }        
        chBoard = board;

        for (int row = 0; row < chBoard.size(); row++)
        {
            for (int col = 0; col < chBoard[row].size(); col++) 
            { 
                for (auto &mapPair : root->nextKeys) 
                {
                    searchMatrix(row, col, mapPair.second);
                }
            }
        }

        vector<string> res;
        for (auto &index : finalList)
        {
            res.push_back(words[index]);
        }
        return res;
    }

    void insertWord(string &word, int index)
    {
        TrieNode *iter = root;
        for (auto &ch : word)
        {
            int key = ch-'a';
            if (iter->nextKeys.find(key) == iter->nextKeys.end()) { iter->nextKeys[key] = new TrieNode(key); }
            iter = iter->nextKeys[key];
        }
        iter->wIndex = index;
    }

    void searchMatrix(int row, int col, TrieNode *rootNode)
    {
        if (row < 0 || row >= chBoard.size()) { return ; }
        if (col < 0 || col >= chBoard[0].size()) { return ; }
        
        int key = chBoard[row][col]-'a';
        if (key == rootNode->key)
        {
            chBoard[row][col] = '*';
            if (rootNode->wIndex != -1) { 
                finalList.push_back(rootNode->wIndex); 
                rootNode->wIndex = -1; // Optimization: avoid duplicate matches
            }
            for (auto &mapPair : rootNode->nextKeys)
            {
                searchMatrix(row+1, col, mapPair.second);
                searchMatrix(row-1, col, mapPair.second);
                searchMatrix(row, col+1, mapPair.second);
                searchMatrix(row, col-1, mapPair.second);
            }
            chBoard[row][col] = (char)(key+'a');
        }
    }

private: 
    TrieNode *root{nullptr};
    vector<int> finalList{};
    vector<vector<char>> chBoard{};
};

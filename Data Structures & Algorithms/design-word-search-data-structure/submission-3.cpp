class WordDictionary {
    struct CharNode
    {
        array<CharNode*, 26U> nextChars{};
        bool endWord{false};
    };
public:
    WordDictionary() : root(new CharNode()) {}
    
    void addWord(string word) 
    {
        CharNode* iter = root;
        for (auto ch : word)        
        {
            int key = ch - 'a';
            if (iter->nextChars[key] == nullptr) { iter->nextChars[key] = new CharNode(); }
            iter = iter->nextChars[key];
        }
        iter->endWord = true;
    }
    
    bool search(string word) 
    {        
        return search(word, root);
    }

    bool search(string word, CharNode* root) 
    {        
        bool found = true;
        CharNode* iter = root;
        if (word.empty() && !iter->endWord) { found = false; }
        for (int i = 0; found && i < word.length(); i++)
        {
            if (word[i] != '.')
            {
                int key = word[i]-'a';
                if (iter->nextChars[key] == nullptr) { found = false; }
                else if (i == word.length()-1 && !iter->nextChars[key]->endWord) { found = false; }
                else { iter = iter->nextChars[key]; }
            }
            else
            {
                string subWord = word.substr(i+1, word.length()-i-1);
                
                bool subFound = false;
                for (int j = 0; !subFound && j < iter->nextChars.size(); j++)
                {
                    if (iter->nextChars[j]) 
                    { 
                        subFound = search(subWord, iter->nextChars[j]); 
                    }
                }
                found = subFound;                
                break;
            }
        }
        return found;
    }

private:
    CharNode* root;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, set<string>> wildcards;

        // insertWord(beginWord, wildcards);
        // insertWord(endWord, wildcards);
        // for (auto &word : wordList) { if (word != beginWord && word != endWord) { insertWord(word, wildcards); } }
        for (auto &word : wordList) { insertWord(word, wildcards); }

        queue<string> potentials;
        potentials.push(beginWord);
        int steps = 0;
        bool found = false;
        set<string> visited;
        while (!potentials.empty() && !found)
        {
            int qLen = potentials.size();
            steps++;
            for (int i = 0; !found && i < qLen; i++)
            {
                string str = potentials.front();
                potentials.pop();
                if (visited.find(str) == visited.end())
                {
                    visited.insert(str);
                    if (str == endWord) { printf("Endword: %s\n", str.c_str()); found = true; }
                    else
                    {
                        for (int j = 0; j < str.length(); j++)
                        {
                            string pattern = str;
                            pattern[j] = '*';
                            printf("Str: %s - ", str.c_str());
                            for (auto & word : wildcards[pattern]) { 
                                if (word != str) { printf("%s, ", word.c_str()); potentials.push(word); }
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }
        return (found)? steps : 0;
    }
    void insertWord(string &word, map<string, set<string>> &wildcards)
    {
        for (int i = 0; i < word.length(); i++)
        {
            string pattern = word;
            pattern[i] = '*';
            wildcards[pattern].insert(word);
        }
    }
};

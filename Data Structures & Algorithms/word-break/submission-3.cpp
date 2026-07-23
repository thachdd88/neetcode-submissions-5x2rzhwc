class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.empty()) { return true; }

        std::sort(wordDict.begin(), wordDict.end(),
        [](const string &s1, const string &s2)
        {
            return (s1.length() > s2.length());
        });

        vector<bool> visited(s.length()+1, false);
        queue<int> process;
        process.push(0);

        bool found{false};
        while (!found && !process.empty())
        {
            auto idx = process.front();
            process.pop();
            for (auto &word : wordDict)
            {
                if (s.find(word, idx) == idx)
                {
                    if ((s.length()-idx) == word.length()) 
                    { 
                        found = true; 
                        break;
                    }
                    else if (!visited[idx+word.length()])
                    {
                        process.push(idx+word.length());
                        visited[idx+word.length()] = true;
                    }
                }
            }
        }
        return found;
    }
};

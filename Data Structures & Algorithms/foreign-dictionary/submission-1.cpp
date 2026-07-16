class Solution {
public:
    string foreignDictionary(vector<string>& words) 
    {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;
        for (auto &word : words)        
            for (auto &ch : word)
            {
                graph[ch].clear();
                inDegree[ch] = 0;
            }

        for (int i = 0; i < words.size()-1; i++)
        {
            auto &w1 = words[i];
            auto &w2 = words[i+1];     
            bool found = false;
            for (int j = 0; j < min(w1.length(), w2.length()); j++)
            {
                if (w1[j] != w2[j])
                {
                    if (graph[w1[j]].find(w2[j]) == graph[w1[j]].end()) 
                    {
                        graph[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found && (w1.length() > w2.length())) { return ""; }
        }
        string res = "";
        queue<char> qc;
        for (auto &node : inDegree) 
        {
            if (node.second == 0) { qc.push(node.first); }
        }
        while (!qc.empty())
        {
            char ch = qc.front();
            qc.pop();
            res = res + ch;
            for (auto next : graph[ch])
            {
                inDegree[next]--;
                if (inDegree[next] == 0) { qc.push(next); }
            }
        }
        if (res.length() != inDegree.size()) { return ""; }
        return res;
    }
};

class Solution {
public:
    string foreignDictionary(vector<string>& words) 
    {
        int n = 26;
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> inDegree(n, -1);
        int numKeys = 0;
        for (auto &word : words)        
            for (auto &ch : word)
            {
                int key = ch - 'a';
                if (inDegree[key] == -1) { numKeys++; }                
                inDegree[key] = 0;
            }

        for (int i = 0; i < words.size()-1; i++)
        {
            auto &w1 = words[i];
            auto &w2 = words[i+1];     
            bool found = false;
            for (int j = 0; j < min(w1.length(), w2.length()); j++)
            {
                int k1 = w1[j] - 'a';
                int k2 = w2[j] - 'a';
                if (k1 != k2)
                {
                    if (!graph[k1][k2])
                    {
                        graph[k1][k2] = true;
                        inDegree[k2]++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found && (w1.length() > w2.length())) { return ""; }
        }
        string res = "";
        queue<int> qc;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0) { qc.push(i); }
        }
        while (!qc.empty())
        {
            int ch = qc.front();
            qc.pop();
            res = res + (char)(ch+'a');
            for (int i = 0; i < n; i++)
            {
                if (graph[ch][i] && inDegree[i] > 0)
                {
                    inDegree[i]--;
                    if (inDegree[i] == 0) { qc.push(i); }
                }
            }
        }
        if (res.length() != numKeys) { return ""; }
        return res;
    }
};

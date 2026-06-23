class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum2(0, candidates, target);
    }
    vector<vector<int>> combinationSum2(int idx, vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        if (idx == candidates.size())
        {
            if (target == 0) { res.push_back(vector<int>()); }
            return res; 
        }

        int next = idx+1;
        while ((next < candidates.size()) && (candidates[next] == candidates[next-1])) { next++; } 
        res = combinationSum2(next, candidates, target);
        if (target >= candidates[idx])
        {
            auto sub = combinationSum2(idx+1, candidates, target-candidates[idx]);
            int n = sub.size();
            for (int i = 0; i < n; i++)
            {
                sub[i].push_back(candidates[idx]);
                res.push_back(sub[i]);
            }
        }
        return res;
    }
};

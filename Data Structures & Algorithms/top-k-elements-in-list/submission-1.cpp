class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto num : nums) { freq[num] += 1; }
        
        std::vector<std::pair<int, int>> freq_vec(freq.begin(), freq.end());
        sort(freq_vec.begin(), freq_vec.end(), 
        [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i++) { res.push_back(freq_vec[i].first); }
        return res;
    }
    
};

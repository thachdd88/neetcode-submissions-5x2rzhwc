class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>prefixMap{};
        int prefixSum{0};
        prefixMap[0] = 1;
        int res{0};
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if (prefixMap.find(prefixSum-k) != prefixMap.end()) {
                res += prefixMap[prefixSum-k];
            }
            prefixMap[prefixSum] += 1;
        }
        
        return res;
    }
};
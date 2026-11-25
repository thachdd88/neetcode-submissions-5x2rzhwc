class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> numMap{};
        int left = 0, right = 0, n = nums.size();
        vector<int> res{};
        while (right < n) {
            numMap[nums[right]]++;
            if (right-left+1 == k) {
                auto last = std::prev(numMap.end());
                res.push_back(last->first);
                numMap[nums[left]]--;
                if (numMap[nums[left]] == 0) {numMap.erase(nums[left]); }
                left++;
            }
            right++;            
        }
        return res;
    }
};

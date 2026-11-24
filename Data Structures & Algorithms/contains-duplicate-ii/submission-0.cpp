class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mapPos{};
        for (int i = 0; i < nums.size(); i++) {
            if (mapPos.find(nums[i]) == mapPos.end()) { mapPos[nums[i]] = i; }
            else {
                if (i - mapPos[nums[i]] <= k) { return true; }
                else { mapPos[nums[i]] = i; }
            }
        }
        return false;
    }
};
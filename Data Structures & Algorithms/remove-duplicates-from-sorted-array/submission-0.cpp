class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> uniques{};
        for (int num : nums) {
            if (uniques.empty() || num != uniques.back()) {
                uniques.push_back(num);
            }
        }
        for (int i = 0; i < uniques.size(); i++) {
            nums[i] = uniques[i];
        }
        return uniques.size();
    }
};
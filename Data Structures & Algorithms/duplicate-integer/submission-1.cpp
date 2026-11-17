class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> set_;
        for (int num : nums) {
            if (set_.find(num) != set_.end()) { return true; }
            set_.insert(num);
        }
        return false;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        checked = vector<bool>(n, false);
        int sum{0};
        for (auto &num : nums) { sum += num; }
        if (sum % 2 != 0) { return false; }
        return findSum(sum/2, nums);
    }

    bool findSum(int sum, vector<int> &nums)
    {
        bool found{false};
        for (int i = 0; sum > 0 && !found && i < n; i++)
        {
            if (!checked[i])
            {
                if (nums[i] == sum) { found = true; }
                else
                {
                    checked[i] = true;
                    found = findSum(sum-nums[i], nums);
                    checked[i] = false;
                }
            }
        }
        return found;
    }

private:
    int n{0};
    vector<bool> checked;
};

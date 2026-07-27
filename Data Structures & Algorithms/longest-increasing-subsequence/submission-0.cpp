class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {   
        n = nums.size();
        counts = vector<int>(n, -1);
        countMax(0, nums);
        int cnt{0};
        for (int i = 0; i < n; i++)
        {
            if (counts[i] == -1) { countMax(i, nums); }
            cnt = max(cnt, counts[i]);
        }
        return cnt;
    }

    void countMax(int idx, vector<int> &nums)
    {
        int cnt{0};
        for (int i = idx+1; i < n; i++)
        {
            if (nums[i] > nums[idx])
            {
                if (counts[i] == -1) { countMax(i, nums); }
                cnt = max(cnt, counts[i]);
            }
        }
        counts[idx] = cnt+1;
        // printf("idx: %d, cnt: %d\n", idx, counts[idx]);
    }
private:
    int n{0};
    vector<int> counts;
};

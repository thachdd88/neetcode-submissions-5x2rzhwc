class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start{0}, end{static_cast<int>(nums.size())-1};

        int res{-1};
        if (!nums.empty())
        {
            if (nums[start] == target) { res = start; }
            else if (nums[end] == target) { res = end; }
            else
            {
                while (end-start > 1)
                {
                    int middle = (start + end)/2;
                    if (target > nums[middle]) { start = middle; }
                    else if (target < nums[middle]) { end = middle; }
                    else
                    {
                        res = middle;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

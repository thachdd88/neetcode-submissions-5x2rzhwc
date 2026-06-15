class Solution {
public:
    int findMin(vector<int> &nums) {
        int left{0}, right{static_cast<int>(nums.size())-1};
        
        int cnt = 0;
        while (right > left)
        {
            int mid = (left+right)/2;
            if (nums[mid] > nums[right]) { left = mid+1; }
            else { right = mid; }
        }
        return nums[left];
    }
};

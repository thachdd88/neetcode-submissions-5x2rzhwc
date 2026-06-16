class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{0}, right{static_cast<int>(nums.size())-1};
        
        int tarIdx{-1};
        int cnt=0;
        while (left <= right)
        {
            int mid = (left+right)/2;
            // printf("%d, %d, %d\n", left, mid, right);

            if (target == nums[left]) { tarIdx = left; break; }
            if (target == nums[mid]) { tarIdx = mid; break; }
            if (target == nums[right]) { tarIdx = right; break; }

            if (nums[mid] > nums[right]) // mid belongs to left segment
            {
                if ((target > nums[mid]) || (target < nums[right])) // target belongs to right segment
                {
                    if (left < mid) { left = mid; }
                    else { break; }
                }
                else // left < target < mid
                {
                    if (right > mid-1) { right = mid-1; }
                    else { break; }
                }
            } 
            else if (nums[mid] < nums[left]) // mid belongs to right segment
            {
                if ((target < nums[mid]) || (target > nums[left])) // target belongs to left segment
                {
                    if (right > mid-1) { right = mid-1; }
                    else { break; }
                }
                else // mid < target < right 
                {
                    if (left < mid) { left = mid; }
                    else { break; }
                }
            }
            else // left < mid < right
            {
                if (target < nums[mid]) 
                { 
                    if (right > mid-1) { right = mid-1; }
                    else { break; }
                }
                else if (target > nums[mid]) 
                { 
                    if (left < mid) { left = mid; }
                    else { break; }
                }
                else
                {
                    tarIdx = mid;
                    break;
                }
            }
            // if (cnt++ > 5) { break; }
        }
        return tarIdx;
    }
};

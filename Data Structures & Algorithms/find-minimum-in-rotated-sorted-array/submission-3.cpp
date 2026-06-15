class Solution {
public:
    int findMin(vector<int> &nums) {
        int left{0}, right{static_cast<int>(nums.size())-1};
        
        int minimum{-1};
        int cnt = 0;
        while (right >= left)
        {
            // printf("%d, %d\n", left, right);
            if (nums[left] < nums[right])
            {
                minimum = nums[left];
                break;
            }
            else if ((right == left+1) || (right == left))
            {
                minimum = nums[right];
                break;
            }
            int mid = (left+right)/2;
            if (nums[mid] < nums[left]) { right = mid; }
            if (nums[mid] > nums[right]) { left = mid; }
            // else 
            // {
            //     minimum = nums[left];
            //     break;
            // }
            // if (cnt++ > 5) { break; }
        }

        return minimum;
    }
};

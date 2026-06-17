class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Treat array as linked list where num[i] points to the element at index nums[i]
        int slow = nums[0];
        int fast = nums[0];        
        do 
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

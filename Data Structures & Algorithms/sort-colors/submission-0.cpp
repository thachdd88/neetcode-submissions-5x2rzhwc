class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
    }
    void quickSort(vector<int> &nums, int start, int end) {
        if (end-start+1 <= 1) { return; }
        int pivot = nums[end];
        int i = start, j = start;
        while (j < end) {
            if (nums[j] < pivot) {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                i++;
            }
            j++;
        }
        nums[end] = nums[i];
        nums[i] = pivot;
        quickSort(nums, start, i-1);
        quickSort(nums, i+1, end);
    }
};
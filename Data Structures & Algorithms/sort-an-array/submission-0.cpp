class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }

    vector<int> mergeSort(vector<int> &nums, int start, int end) {
        if (end-start+1 <= 1) { return vector<int>(1, nums[start]); }
        int mid = (end+start)/2;
        vector<int> left = mergeSort(nums, start, mid);
        vector<int> right = mergeSort(nums, mid+1, end);

        // merge
        vector<int> merged{};
        int lIdx = 0, rIdx = 0;
        while (lIdx < left.size() && rIdx < right.size()) {
            if (left[lIdx] <= right[rIdx]) {
                merged.push_back(left[lIdx]);
                lIdx++;
            } else  {
                merged.push_back(right[rIdx]);
                rIdx++;
            }
        }
        while (lIdx < left.size()) {
            merged.push_back(left[lIdx]);
            lIdx++;
        }
        while (rIdx < right.size()) {
            merged.push_back(right[rIdx]);
            rIdx++;
        }
        return merged;
    }
};
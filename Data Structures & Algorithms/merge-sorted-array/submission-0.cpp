class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            int idx = m+i;
            while (idx > 0 && (nums1[idx-1]) > nums2[i]) {
                nums1[idx] = nums1[idx-1];
                idx--;
            }
            nums1[idx] = nums2[i];
        }
    }
};
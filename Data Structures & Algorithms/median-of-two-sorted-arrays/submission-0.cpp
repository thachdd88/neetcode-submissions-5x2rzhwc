class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = static_cast<int>(nums1.size());
        int n2 = static_cast<int>(nums2.size());
        int total = n1 + n2;
        int idx1{0}, idx2{0}, lastNum{0};
        int mIdx{0};
        float median{0.0};
        while (mIdx < total)
        {
            if (idx1 >= n1) { lastNum = nums2[idx2]; idx2++; }
            else if (idx2 >= n2) { lastNum = nums1[idx1]; idx1++; }
            else
            {
                if (nums1[idx1] < nums2[idx2]) { lastNum = nums1[idx1]; idx1++; }
                else { lastNum = nums2[idx2]; idx2++; }
            }
            // printf("%d\n", lastNum);

            if (total % 2 == 0) 
            {
                if (mIdx == total/2 - 1) { median += lastNum/2.0; }
                if (mIdx == total/2) { median += lastNum/2.0; break; }
            }
            else
            {
                if (mIdx == total/2) { median = lastNum; break; }
            }
            mIdx++;
        }
        return median;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int gap = 0; // abs(arr[0]-x);
        int minGap = 1000000; int minL{-1}, minR{-1};
        int left = 0, right = 0;
        while (right < n) {
            gap += abs(arr[right]-x);
            if (right-left+1 < k) {
                right++;
            }
            else {
                if (gap < minGap) {
                    minGap = gap;
                    minL = left;
                    minR = right;                    
                }
                gap -= abs(arr[left]-x);
                left++, right++;
            }
        }
        if (minL == -1) {
            minL = left-1;
            minR = right-1;
        }
        vector<int> res{};
        for (int i = minL; i <= minR; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
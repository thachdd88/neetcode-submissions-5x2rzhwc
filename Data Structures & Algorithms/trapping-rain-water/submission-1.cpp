class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        int maxL{0}, maxR{0};
        for (int i = 0; i < n; i++)
        {
            leftMax[i] = max(maxL, heights[i]);
            maxL = leftMax[i];

            rightMax[n-i-1] = max(maxR, heights[n-i-1]);
            maxR = rightMax[n-i-1];            
        }
        int amount=0;
        for (int i = 0; i < n; i++)
        {
            amount += min(leftMax[i], rightMax[i])-heights[i];
        }
        return amount;
    }
};

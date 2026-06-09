class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmount = 0;
        int start = 0;
        int end = heights.size()-1;
        while (start < end)
        {
            int amount = (end-start)*min(heights[end], heights[start]);
            if (maxAmount < amount) { maxAmount = amount; }
            if (heights[end] < heights[start]) { end--; }
            else { start++; }
        }
        return maxAmount;
    }
};

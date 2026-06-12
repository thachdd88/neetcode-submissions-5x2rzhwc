class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxVol{0};

        for (int i = 0; i < heights.size(); i++)
        {
            int vol = heights[i];
            int left{i-1}, right{i+1};
            while ((left >= 0) || (right < heights.size()))
            {
                bool running=false;
                if ((left >= 0) && (heights[left] >= heights[i]))
                {
                    vol += heights[i];
                    left--;
                    running = true;
                }
                if ((right < heights.size()) && (heights[right] >= heights[i]))
                {
                    vol += heights[i];
                    right++; 
                    running = true;
                }
                if (!running) { break; }                
            }
            if (maxVol < vol) { maxVol = vol; }
        }
        return maxVol;
    }
};

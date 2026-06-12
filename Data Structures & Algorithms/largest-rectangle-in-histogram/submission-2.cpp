class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int maxVol{0};

        vector<int> slp(n); // small left pos
        {
            stack<int> smallStk;
            for (int i = 0; i < n; i++)
            {
                while (!smallStk.empty() && heights[smallStk.top()] >= heights[i]) { smallStk.pop(); }
                slp[i] = (!smallStk.empty())? smallStk.top() : -1;
                smallStk.push(i);
            }
        }
        // printf("left: %d, %d, %d, %d, %d, %d\n", slp[0], slp[1], slp[2], slp[3], slp[4], slp[5]);
        
        vector<int> srp(n); // small right pos
        {
            stack<int> smallStk;
            for (int i = n-1; i >= 0; i--)
            {
                while (!smallStk.empty() && heights[smallStk.top()] >= heights[i]) { smallStk.pop(); }
                srp[i] = (!smallStk.empty())? smallStk.top() : n;
                smallStk.push(i);
            }
        }
        // printf("right: %d, %d, %d, %d, %d, %d\n", srp[0], srp[1], srp[2], srp[3], srp[4], srp[5]);

        for (int i = 0; i < n; i++)
        {
            int vol = (srp[i]-1) - (slp[i]+1) + 1;
            vol *= heights[i];
            maxVol = max(maxVol, vol);
        }
        return maxVol;
    }
    int largestRectangleArea_bak(vector<int>& heights) {
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

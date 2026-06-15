class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = 1;
        int maxK = 0;
        for (auto &pile : piles) { maxK = max(maxK, pile); }
        
        int midK, finalK;
        while (maxK >= minK)
        {
            midK = (minK + maxK) / 2;
            int time{0};
            for (auto &pile : piles)
            {
                time += pile / midK;
                if (pile % midK > 0) { time++;}                
            }
            if (time <= h) { maxK = midK-1; finalK = midK; }
            else { minK = midK+1; }
        }
        return finalK;
    }
};

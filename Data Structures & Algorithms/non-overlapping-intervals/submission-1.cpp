class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        
        int cnt{0};
        int lastEnd{-50000};
        for (auto &interval : intervals) {
            if (lastEnd > interval[0]) { cnt++; lastEnd = min(lastEnd, interval[1]); }
            else { lastEnd = interval[1]; }
        }

        return cnt;
    }
};

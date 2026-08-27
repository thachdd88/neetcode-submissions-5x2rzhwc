class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{};
        int idx;
        for (idx = 0; idx < intervals.size(); idx++) {
            if (intervals[idx][0] > newInterval[0]) { break; }
            res.push_back(intervals[idx]);
        }
        if (idx > 0) {
            if (res[idx-1][1] < newInterval[0]) { res.push_back(newInterval); }
            else {
                if (res[idx-1][1] < newInterval[1]) { res[idx-1][1] = newInterval[1]; }
            }
        }
        else { res.push_back(newInterval); }
        
        // if (res.back()[1] >= intervals[idx][0]) {
        //     if (res.back()[1] < intervals[idx][1]) { res.back()[1] = intervals[idx][1]; }
        //     idx++;
        // }   
        
        // for (int i = idx; i < intervals.size(); i++) {     
        //     res.push_back(intervals[idx]);
        // }
        while (idx < intervals.size()) {
            if (res.back()[1] >= intervals[idx][0]) {
                if (res.back()[1] < intervals[idx][1]) { res.back()[1] = intervals[idx][1]; }
            }   
            else { res.push_back(intervals[idx]); }
            idx++;
        }
        return res;
    }
};

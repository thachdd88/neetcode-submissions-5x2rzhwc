class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        set<pair<int, int>> sorted;
        for (auto &interval : intervals) {
            sorted.insert({interval[0], interval[1]});
        }
        for (auto &interval : sorted) {
            printf("interval: %d-%d\n", interval.first, interval.second);
        }

        vector<vector<int>> res{};
        for (auto &interval : sorted) {
            if (res.empty()) {
                res.push_back({interval.first, interval.second});
            }
            else if (res.back()[1] < interval.first) {
                res.push_back({interval.first, interval.second});
            }
            else {
                res.back()[1] = max(res.back()[1], interval.second);
            }
        }

        return res;
    }
};

class Solution {
public:
#if 1
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>qId(queries.size());
        iota(qId.begin(), qId.end(), 0);
        sort(qId.begin(), qId.end(), [&queries](const int &lhs, const int &rhs) {
            return queries[lhs] < queries[rhs];
        });
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });

        vector<int> res(queries.size(), -1);
        int iId{0};
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> minHeap{};
        for (auto &id : qId) {
            while(iId < intervals.size() && intervals[iId][0] <= queries[id]) {
                minHeap.push({intervals[iId][1]-intervals[iId][0]+1, intervals[iId][1]});
                iId++;
            }

            while (!minHeap.empty() && minHeap.top().second < queries[id]) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                res[id] = minHeap.top().first;
            }
        }
        return res;
    }
#else
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        vector<int> res{};
        for (auto query : queries) {
            int minInt{10000001};
            for (int i = 0; i < intervals.size() && intervals[i][0] <= query; i++) {
                if (query <= intervals[i][1]) { minInt = min(minInt, intervals[i][1]-intervals[i][0]+1); }
            }
            if (minInt == 10000001) { minInt = -1; }
            res.push_back(minInt);
        }
        return res;
    }
#endif
};

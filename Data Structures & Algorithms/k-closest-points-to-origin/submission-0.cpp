class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) 
        {
            double dista = sqrt(a[0]*a[0]+a[1]*a[1]);
            double distb = sqrt(b[0]*b[0]+b[1]*b[1]);
            return dista >= distb;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pQueue(points.begin(), points.end());
        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pQueue.top());
            pQueue.pop();
        }
        return res;
    }
};

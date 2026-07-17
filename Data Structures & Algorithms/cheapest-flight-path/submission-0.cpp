class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        int inf = 100000;
        vector<vector<int>> costs(n, vector<int>(n, inf));
        for (auto &flight : flights) { costs[flight[0]][flight[1]] = flight[2]; }

        vector<int> minStops(n, inf);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> dest;
        dest.push({0, 0, src});

        while (!dest.empty())
        {
            auto [dist, stops, idx] = dest.top();
            dest.pop();
                  
            if (idx == dst) { return dist; }   

            if (stops > k || stops >= minStops[idx]) { continue; }   
            minStops[idx] = stops;
            
            for (int j = 0; j < n; j++)
            {
                if (costs[idx][j] < inf)
                {
                    dest.push({dist+costs[idx][j], minStops[idx]+1, j});
                }
            }
        }
        return -1;
    }
};

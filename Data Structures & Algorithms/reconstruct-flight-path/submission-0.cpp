class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {        
        auto cmp = [](const string &s1, const string &s2) { return s1 > s2; };
        // map<string, priority_queue<string, vector<string>, decltype(cmp)>> connections;
        map<string, priority_queue<string, vector<string>, std::greater<string>>> connections;
        for (auto &flight : tickets) { connections[flight[0]].push(flight[1]); }
        // for (auto &airport : connections)
        // {
        //     printf("%s: ", airport.first.c_str());
        //     while (!airport.second.empty()) { printf("%s, ", airport.second.top().c_str()); airport.second.pop(); }
        //     printf("\n");
        // }

        vector<string> res;
        stack<string> travel;
        travel.push("JFK");
        while (!travel.empty())
        {
            auto dest = travel.top();
            if (!connections[dest].empty())
            {
                auto next = connections[dest].top();
                connections[dest].pop();
                travel.push(next);
            }
            else
            {
                res.push_back(dest);
                travel.pop();
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

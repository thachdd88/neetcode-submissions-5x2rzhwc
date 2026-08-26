class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> filtered{};
        for (int i = 0; i < triplets.size(); i++)        
        {
            if ((triplets[i][0] <= target[0]) && (triplets[i][1] <= target[1]) && (triplets[i][2] <= target[2]))
            {
                filtered.push_back(triplets[i]);
            }
        }
        bool foundX{false}, foundY{false}, foundZ{false};
        for (int i = 0; i < filtered.size(); i++)  
        {
            if (filtered[i][0] == target[0]) { foundX = true; }
            if (filtered[i][1] == target[1]) { foundY = true; }
            if (filtered[i][2] == target[2]) { foundZ = true; }
            if (foundX && foundY && foundZ) { break; }
        }
        return foundX && foundY && foundZ;
    }
};

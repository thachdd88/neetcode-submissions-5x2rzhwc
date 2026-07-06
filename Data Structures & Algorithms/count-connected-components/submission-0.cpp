class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        for (auto &edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }

        int label = 1;
        for (int node = 0; node < n; node++)
        {
            if (marks[node] == 0) { labeling(node, label); label++; }
        }
        return label-1;
    }
    void labeling(int node, int label)
    {
        if (marks[node] != 0) { return; }
        else
        {
            marks[node] = label;
            for (auto connection : connections[node]) { labeling(connection, label); }
        }
    }

private:
    map<int, vector<int>> connections;
    map<int, int> marks; 
};

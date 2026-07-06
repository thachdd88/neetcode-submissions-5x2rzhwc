class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        marks = vector<int>(n, 0);
        for (auto &edge : edges) 
        { 
            connections[edge[0]].push_back(edge[1]); 
            connections[edge[1]].push_back(edge[0]);
        }
        bool valid = true; 
        // for (int node = 0; valid && node < n; node++)
        // {
        //     valid = markingNode(node, -1);
        // }
        valid = markingNode(0, -1);
        if (valid)
        {
            for (auto &mark : marks)
            {
                if (mark == 0)
                {
                    valid = false;
                    break;
                }
            }
        }
        return valid; 
    }

    bool markingNode(int idx, int parent)
    {
        if (marks[idx] < 0) { printf("parent: %d, child: %d (%d)\n", parent, idx, marks[idx]); return false; }
        else
        {
            marks[idx] = -1;
            bool valid = true; 
            for (int i = 0; valid && i < connections[idx].size(); i++)
            {
                if (connections[idx][i] != parent) {
                    printf("Check parent: %d, child: %d\n", idx, connections[idx][i]);
                    valid = markingNode(connections[idx][i], idx);}
            }
            if (valid) {marks[idx] = 1;}
            return valid; 
        }
    }

private:
    map<int, vector<int>> connections;
    vector<int> marks;
};

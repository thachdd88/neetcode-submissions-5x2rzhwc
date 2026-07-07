class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        parent = vector<int>(edges.size()+1);
        rank = vector<int>(edges.size()+1, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            parent[i+1] = i+1;
        }
        vector<int> res;
        for (auto &edge : edges)
        {
            if (!updateUnion(edge[0], edge[1])) { res = edge; break; }
        }
        return res;
    }
    bool updateUnion(int nodeA, int nodeB)
    {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);
        
        if (rootA == rootB) { return false; }

        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else
        {
            parent[rootA] = rootB;
            rank[rootB]++;
        }

        return true; 
    }
    int findRoot(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = findRoot(parent[node]);
        }
        return parent[node];
    }

private:
    vector<int> parent;
    vector<int> rank;
};

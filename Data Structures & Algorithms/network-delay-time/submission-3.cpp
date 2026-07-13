class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {  
        int INF = 1000000;
        n = n + 1;
        vector<int> delays(n, INF);
        delays[0] = 0;
        delays[k] = 0;

        for (int iter = 0; iter < n-1; iter++)
        {
            bool updated = false;
            for (auto &signal : times)
            {
                int u = signal[0], v = signal[1], duv = signal[2];
                if (delays[u] != INF && delays[v] > delays[u] + duv)
                {
                    delays[v] = delays[u] + duv;
                    updated = true;
                }
            }
            if (!updated) { break; }
        }
        int delayMax = 0;
        for (auto node : delays)
        {
            if (node == INF)
            {
                delayMax = -1;
                break;
            }
            if (node > delayMax) { delayMax = node; }
        }

        return delayMax;
    }
    void printTime(vector<int> &times)
    {
        printf("Times: ");
        for (int k = 1; k < times.size(); k++) { printf("%d[%d], ", k, times[k]); }
        printf("\n");
    }
};

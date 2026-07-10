class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        n = n+1;
        vector<vector<int>> timetable(n, vector<int>(n, -1));
        for (auto &edge : times) { timetable[edge[0]][edge[1]] = edge[2]; }
        vector<int> timelap(n, -1);        

        bool allDone = false;
        int timeCnt = -1;
        queue<pair<int, int>> updates{};  
        updates.push({k, 1});
        while (!allDone || !updates.empty())
        {   
            while (!updates.empty())
            {
                auto qNode = updates.front();
                updates.pop();

                timelap[qNode.first] = qNode.second;              
            }

            allDone = true;            
            for (int node = 0; node < n; node++)
            {
                if (timelap[node] > 0) 
                { 
                    timelap[node]--; 
                    if (timelap[node] == 0)
                    {
                        for (int i = 1; i < n; i++)                        
                        {
                            if (timetable[node][i] != -1 && (timelap[i] == -1 || timelap[i] > timetable[node][i]))
                            {
                                updates.push({i, timetable[node][i]});
                            }
                        }
                    }
                    else { allDone = false; }
                }
            }
            printTime(timelap);
            timeCnt++;
        }
      
        for (int node = 1; node < n; node++)
        {
            if (timelap[node] == -1) 
            {
                timeCnt = -1;
                break;
            }
        }
        return timeCnt;        
    }
    void printTime(vector<int> &times)
    {
        printf("Times: ");
        for (int k = 1; k < times.size(); k++) { printf("%d[%d], ", k, times[k]); }
        printf("\n");
    }
};

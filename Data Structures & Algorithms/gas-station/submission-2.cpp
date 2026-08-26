class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        bool success(false);
        int start;
        for (start = 0; start < n; start++) {
            int curGas = gas[start]-cost[start];
            int station = (start+1) % n;
            while (curGas > 0 && station != start) {
                curGas += gas[station]-cost[station];
                station = (station+1) % n;
            }        
            success = (curGas >= 0) && (station == start);
            if (success) { break; }
        }
        return success? start : -1;
    }
};

class CountSquares {
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        pCnt[point[0]][point[1]]++;        
    }
    
    int count(vector<int> point) {
        int cnt{0};
        int x0 = point[0];
        int y0 = point[1];
        for (auto &py : pCnt[x0]) {
            int y1 = py.first;
            int delt = abs(y0 - y1);
            if (delt > 0) {
                cnt += pCnt[x0][y1]*pCnt[x0+delt][y1]*pCnt[x0+delt][y0];
                cnt += pCnt[x0][y1]*pCnt[x0-delt][y1]*pCnt[x0-delt][y0];
            }
        }
        return cnt;
    }

private:
    map<int, map<int, int>> pCnt{};
};

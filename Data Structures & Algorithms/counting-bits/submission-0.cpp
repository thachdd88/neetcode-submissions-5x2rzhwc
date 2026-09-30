class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        for (int i = 1; i <= n; i++) {
            int base = i & (i-1);
            res[i] = res[base]+1;
        }
        return res;
    }
};

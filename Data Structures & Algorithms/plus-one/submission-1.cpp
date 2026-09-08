class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        int counter = 1;
        for (int i = res.size()-1; i >= 0; i--) {
            int k = res[i] + counter;
            res[i] = k % 10;
            counter = k / 10;
        }
        if (counter > 0) { res.insert(res.begin(), counter); }
        
        return res;
    }
};

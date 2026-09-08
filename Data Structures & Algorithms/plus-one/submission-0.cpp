class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> resInv{};
        int counter = 1;
        for (int i = digits.size()-1; i >= 0; i--) {
            int k = digits[i] + counter;
            resInv.push_back(k % 10);
            counter = k / 10;
        }
        if (counter > 0) { resInv.push_back(counter); }
        vector<int> res{};
        for (int i = resInv.size()-1; i >= 0; i--) { res.push_back(resInv[i]); }
        return res;
    }
};

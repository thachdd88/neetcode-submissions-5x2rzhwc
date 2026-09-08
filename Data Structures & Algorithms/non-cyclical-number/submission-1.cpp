class Solution {
public:
    bool isHappy(int n) {
        set<int> record{};
        while (record.find(n) == record.end() && n > 1) {
            record.insert(n);
            int k{0};
            while (n > 0) {
                k += pow(n % 10, 2);
                n = n / 10;
            }
            n = k;
        }
        return n == 1;
    }
};

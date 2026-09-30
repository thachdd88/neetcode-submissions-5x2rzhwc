class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0)? -1 : 1;        
        int idx{0};
        int res{0};
        if (verify(x)) {
            x = abs(x);
            while (x > 0) {
                int digit = x % 10;
                res = res*10 + digit; 
                    idx++; x = x/10;
            }
        }
        return res*sign; 
    }
    bool verify(int x) {
        // 2147483648
        array<int, 10U> maxDigits{2, 1, 4, 7, 4, 8, 3, 6, 4, (x < 0)?8:7};
        x = abs(x);
        bool valid = (x < 1000000000);
        int idx{0};
        while (!valid) {
            int digit = x % 10;
            if (digit < maxDigits[idx]) { valid = true; }
            else if (digit > maxDigits[idx]) { break; }
            else { idx++; x = x/10;}
        }
        return valid; 
    }
};

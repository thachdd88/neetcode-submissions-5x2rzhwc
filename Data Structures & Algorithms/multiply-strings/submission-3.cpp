class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "0";
        int l1 = num1.length();
        int l2 = num2.length();
        string zeros = "";
        for (int i = 0; i < l1; i++) {
            int n1 = (int) (num1[l1-i-1]-'0');
            string s1 = zeros;
            int mem = 0;
            for (int j = 0; j < l2; j++) {
                int n2 = (int) (num2[l2-j-1]-'0');
                int prod = n1*n2+mem;
                mem = prod / 10;
                prod = prod % 10;
                s1.push_back(static_cast<char>(prod+48));
            }
            if (mem > 0) { s1.push_back(static_cast<char>(mem+48)); }
            reverse(s1.begin(), s1.end());
            if (!checkZero(s1)) { res = addStr(s1, res); }

            zeros = zeros + '0';
        }
        return res;
    }
    bool checkZero(string &num) {
        for (int i = 0; i < num.length(); i++) {
            if (num[i] != '0') { return false; }
        }
        return true;
    }
    string addStr(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        int n = max(l1, l2);
        int mem{0};
        string res;
        res.reserve(n+1);
        for (int i = 0; i < n; i++) {            
            int n1 = (i < l1)? (int) (num1[l1-i-1]-'0') : 0;
            int n2 = (i < l2)? (int) (num2[l2-i-1]-'0') : 0;
            int n3 = n1+n2+mem;
            mem = n3 / 10;
            n3 = n3 % 10;
            res.push_back(static_cast<char>(n3+48));
        }
        if (mem > 0) { res.push_back(static_cast<char>(mem+48)); }
        reverse(res.begin(), res.end());
        return res;
    }
};

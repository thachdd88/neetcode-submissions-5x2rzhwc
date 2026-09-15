class Solution {
public:
    string multiply(string num1, string num2) {        
        int l1 = num1.length();
        int l2 = num2.length();
        
        vector<int> prod(l1+l2, 0);
        for (int i = l1-1; i >= 0; i--) {
            int n1 = (int) (num1[i]-'0');
        
            for (int j = l2-1; j >= 0; j--) {
                int n2 = (int) (num2[j]-'0');

                prod[i+j+1] += n1*n2;
                prod[i+j] += prod[i+j+1] / 10;
                prod[i+j+1] = prod[i+j+1] % 10;        
            }        
        }

        string res;
        int start = 0;
        while (start < l1+l2-1 && prod[start] == 0) { start++; }
        
        for (int i = start; i < l1+l2; i++) {
            res.push_back((char)(prod[i]+48));
        }

        return res;
    }
};

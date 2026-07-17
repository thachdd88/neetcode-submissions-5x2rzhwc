class Solution {
public:
    int climbStairs(int n) 
    {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        int i = 1;
        int pre = 1;
        int res = 1;
        while (i < n)
        {
            int  temp = res;
            res += pre;
            pre = temp;
            i++;
        }
        return res; 
    }
};

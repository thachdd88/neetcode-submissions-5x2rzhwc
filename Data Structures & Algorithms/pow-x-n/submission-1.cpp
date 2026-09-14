class Solution {
public:
    double myPow(double x, int n) {
        double xsqr = x;
        int nabs = (n > 0) ? n : -n;
        double resx = 1.0;
        while (nabs > 0) {
            if ((nabs & 1) != 0) { resx *= xsqr; }
            xsqr *= xsqr;
            nabs = nabs >> 1;
        }
        if (n < 0) { resx = 1/resx; }
        return resx;
    }
};

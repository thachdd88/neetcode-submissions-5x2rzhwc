class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int sum = n*((n+1)/2) + ((n%2 == 0) ? n/2 : 0);
        int sum = n*(n+1)/2;
        for (auto num : nums) { sum -= num; }
        return sum;
    }
};
// 1 2 = 3*1;
// 1 2 3 = 4*1 + 2 = 2*(2+1)
// 1 2 3 4 = 5*4
// 1 2 3 4 5 = 5*3
// 1 2 3 4 5 6 = 6*3 + 3

// n*(n+1)/2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*((n+1)/2) + ((n%2 == 0) ? n/2 : 0);
        // printf("%d, %d, %d\n", n, (n+1)/2, sum);
        // sum += ((n%2 == 0) ? n/2 : 0);
        // printf("%d, %d\n", n, sum);
        for (auto num : nums) { sum -= num; }
        return sum;
    }
};
// 0 1 2 = 2*1 + 1;
// 0 1 2 3 = 3*2
// 0 1 2 3 4 = 4*2 + 2
// 0 1 2 3 4 5 = 5*3
// 0 1 2 3 4 5 6 = 6*3 + 3

// n*(n+1)/2
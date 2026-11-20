class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Count the 2 max-amount numbers
        int cnt1{0}, cnt2{0};
        int num1{0}, num2{0};
        for (int num : nums) {
            if (num == num1) { cnt1++; }
            else if (num == num2) { cnt2++;}
            else if (cnt1 == 0) {
                num1 = num;
                cnt1++;
            }
            else if (cnt2 == 0) {
                num2 = num;
                cnt2++;
            }
            else {
                cnt1--; cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for (int num : nums) {
            if (num == num1) { cnt1++; }
            if (num == num2) { cnt2++; }
        }
        vector<int> res{};
        if (cnt1 > nums.size()/3) { res.push_back(num1); }
        if (cnt2 > nums.size()/3) { res.push_back(num2); }
        return res;
    }
};
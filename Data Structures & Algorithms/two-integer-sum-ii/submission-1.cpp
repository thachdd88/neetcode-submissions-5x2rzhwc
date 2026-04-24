class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {        
        vector<int> res(2, -1);
        int left=0, right=numbers.size()-1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum > target) { right--; }
            else if (sum < target) { left++; }
            else
            {
                res[0] = left+1;
                res[1] = right+1;
                break;
            }
        }
        return res;
    }
};

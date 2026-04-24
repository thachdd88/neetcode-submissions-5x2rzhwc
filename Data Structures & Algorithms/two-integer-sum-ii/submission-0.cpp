class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> recordNums{};
        vector<int> res(2, -1);
        for (int i=0; i < numbers.size(); i++)
        {
            int sub = target - numbers[i];
            int subIdx = recordNums[sub];
            if (subIdx != 0)
            {
                res[0] = subIdx;
                res[1] = i+1;
                break;
            }
            recordNums[numbers[i]] = i+1;
        }
        return res;
    }
};

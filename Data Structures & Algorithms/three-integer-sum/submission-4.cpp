class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res{};

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int total = sortedNums.size();

        map<pair<int, int>, bool> existedPair{};
        for (int fst = 0; fst < total-2; fst++)
        {
            int target = 0 - sortedNums[fst];
            int left = fst+1;
            int right = total-1;
            while (left < right)
            {
                int sum = sortedNums[left] + sortedNums[right];
                if (sum > target) { right--; }
                else if (sum < target) { left++; }
                else 
                {
                    auto fstLeft = make_pair(sortedNums[fst], sortedNums[left]);
                    if (!existedPair[fstLeft])
                    {
                        vector<int> triplet{};
                        triplet.push_back(sortedNums[fst]);
                        triplet.push_back(sortedNums[left]);
                        triplet.push_back(sortedNums[right]);
                        res.emplace_back(triplet);
                        existedPair[fstLeft] = true;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

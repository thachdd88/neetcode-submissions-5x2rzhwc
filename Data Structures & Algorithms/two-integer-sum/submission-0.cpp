class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> intMap;
        vector<int> indices;
        for (unsigned int i = 0U; i < nums.size(); i++)
        {
            int sub = target - nums[i];
            if (intMap[sub] != 0)
            {
                indices.push_back(i);
                indices.push_back(intMap[sub]-1);
                break;
            }          
            intMap[nums[i]] = i + 1;  
        }   
        sort(indices.begin(), indices.end());
        return indices;
    }
};

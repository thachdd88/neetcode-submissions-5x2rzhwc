class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
                
        /* Forward travel */
        vector<int> fwdNums(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {            
            fwdNums[i] *= fwdNums[i-1]*nums[i-1];            
        }
        /* Backward travel */
        vector<int> bwdNums(nums.size(), 1);
        for (int i = nums.size()-2; i >=0; i--)
        {            
            bwdNums[i] *= bwdNums[i+1]*nums[i+1];      
            // printf("%d: %d, %d, %d\n", i, temp, res[i], nums[i+1]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = fwdNums[i] * bwdNums[i];
        }      

        return res; 
    }
};

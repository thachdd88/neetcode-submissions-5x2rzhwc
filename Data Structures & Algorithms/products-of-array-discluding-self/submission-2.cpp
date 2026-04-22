class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
                
        /* Forward travel */
        for (int i = 1; i < nums.size(); i++)
        {            
            res[i] = res[i-1]*nums[i-1];            
        }
        /* Backward travel */
        int postProd=1;        
        for (int i = nums.size()-2; i >=0; i--)
        {               
            postProd *= nums[i+1];
            res[i] *= postProd; 
            // printf("%d: %d, %d, %d\n", i, temp, res[i], nums[i+1]);
        }    

        return res; 
    }
};

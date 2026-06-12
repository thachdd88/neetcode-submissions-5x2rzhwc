class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size()-1; i++)
        {            
            for (int j = i+1; j < temperatures.size(); j++)
            {
                if (temperatures[j]>temperatures[i]) 
                { 
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};

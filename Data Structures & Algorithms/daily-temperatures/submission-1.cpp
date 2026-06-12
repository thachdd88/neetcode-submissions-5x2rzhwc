class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> res(temperatures.size());
        stack<int> peakIndices;

        for (int i = temperatures.size()-1; i >= 0; i--)
        {
            int cnt{0};
            while (!peakIndices.empty())
            {
                if (temperatures[peakIndices.top()] <= temperatures[i]) { peakIndices.pop(); }
                else
                {
                    cnt = peakIndices.top() - i;
                    break;                    
                }
            }
            res[i] = cnt;
            peakIndices.push(i);
        }
        return res;
    }
    vector<int> dailyTemperatures_bak(vector<int>& temperatures) {
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

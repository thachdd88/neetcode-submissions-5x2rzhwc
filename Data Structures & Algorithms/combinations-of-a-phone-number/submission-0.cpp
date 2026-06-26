class Solution {
public:
    map<char, vector<string>> keyboard = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"q", "p", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };
    vector<string> letterCombinations(string digits) 
    {       
        vector<string> res; 
        if (!digits.empty())
        {
            queue<string> strqueue(keyboard[digits[0]].begin(), keyboard[digits[0]].end());
            for (int d = 1; d < digits.size(); d++)
            {
                char digit = digits[d];
                int qsize = strqueue.size();
                for (int i = 0; i < qsize; i++)
                {
                    auto str = strqueue.front();
                    strqueue.pop();
                    for (auto keychar : keyboard[digit])                                
                    {
                        strqueue.push(str+keychar);
                    }
                }
            }

            int qsize = strqueue.size();
            for (int i = 0; i < qsize; i++)
            {
                res.push_back(strqueue.front());
                strqueue.pop();
            }
        }
        return res;
    }
};

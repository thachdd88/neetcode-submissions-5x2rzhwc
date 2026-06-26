class Solution {
public:
    map<char, string> keyboard = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "qprs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> letterCombinations(string digits) 
    {       
        vector<string> res; 
        if (!digits.empty())
        {
            queue<string> strqueue;
            for (auto keychar : keyboard[digits[0]]) { strqueue.push(std::string()+keychar); }
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

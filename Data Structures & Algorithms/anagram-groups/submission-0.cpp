#include <array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> baseStrs{};
        vector<vector<string>> final;

        for (const auto &str : strs)
        {
            bool newBase = true;
            for (unsigned int i = 0U; i < baseStrs.size(); i++)
            {
                if (isAnagram(str, baseStrs[i]))
                {
                    final[i].push_back(str);
                    newBase = false;
                }
            }
            if (newBase)
            {
                baseStrs.push_back(str);
                final.push_back(vector<string>());
                final.back().push_back(str);
            }
        }
        return final;        
    }
    bool isAnagram(const string &strA, const string &strB)
    {
        if (strA.size() != strB.size()) { return false; }
        array<int, 100U> strCnts{};
        for (unsigned int i = 0U; i < strA.size(); i++)
        {
            strCnts[strA[i]-'A'] += 1;
            strCnts[strB[i]-'A'] -= 1;
        }
        for (auto cnt : strCnts) 
        {
            if (cnt != 0) { return false; }
        }
        return true;
    }
};

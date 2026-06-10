class Solution {
public:
    bool checkDuplicate(const string &str)
    {
        bool found = false;
        map<int, int> existed{};
        for (int j = 0; j < str.length(); j++)
        {
            char ch = str[j];
            if (existed[ch] > 0)
            {
                found = true;
                break;
            }
            existed[ch] = 1;
        }
        return found;
    }
    int lengthOfLongestSubstring(string s) {
        int subSize = 0;
        int len = s.length();
        while (subSize < len)
        {
            subSize++;
            bool found = false;
            for (int i = 0; i < len-subSize+1; i++)
            {
                auto subStr = s.substr(i, subSize);
                if (checkDuplicate(subStr) == false)
                {
                    found = true;
                    break;
                }
                // printf("sub[%d]: %s\n", subSize, subStr.c_str());
            }
            if (!found) { subSize--; break; }
        }
        return subSize;
    }
};

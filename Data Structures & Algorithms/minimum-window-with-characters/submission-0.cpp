class Solution {
public:
    string minWindow(string s, string t)
    {
        string res = "";
        if (s.length() >= t.length())
        {
            unordered_map<char, int> tMap;
            for (int i = 0; i < t.length(); i++) { tMap[t[i]] += 1;}

            unordered_map<char, int> sMap;
            int subSize = t.length();
            int sizeMax = s.length();
            
            int left{0}, right{0};
            sMap[s[left]] = 1;

            bool moveFwd = true;
            while (subSize <= sizeMax)
            {
                if (right-left+1 < subSize)
                {
                    if (moveFwd)
                    {
                        right++;
                        sMap[s[right]] += 1;
                    }
                    else
                    {
                        left--;
                        sMap[s[left]] += 1;
                    }
                }
                else
                {
                    // printf("%s\n", s.substr(left, right-left+1).c_str());                    
                    bool match = true;
                    for (const auto &pair : tMap)
                    {
                        if (sMap[pair.first] < pair.second)
                        {
                            match = false;
                            break;
                        }
                    }
                    if (match) 
                    {
                        res = s.substr(left, right-left+1);
                        break; 
                    } 

                    if (moveFwd)
                    {
                        if (right < sizeMax-1)
                        {
                            sMap[s[left]] -= 1; 
                            left++; right++;
                            sMap[s[right]] += 1;
                        }
                        else 
                        { 
                            moveFwd = false; 
                            subSize++;
                        }
                    }
                    else
                    {
                        if (left > 0)
                        {
                            left--;
                            sMap[s[left]] += 1; 
                            sMap[s[right]] -= 1;
                            right--;
                        }
                        else 
                        { 
                            moveFwd = true; 
                            subSize++;
                        }
                    }
                }
            }
        }
        return res;
    }
    string minWindow_bak(string s, string t) {
        unordered_map<char, int> tMap;
        for (int i = 0; i < t.length(); i++) { tMap[t[i]] += 1;}

        unordered_map<char, int> sMap;
        int right{0};
        bool match = false;
        while (right < s.length())
        {
            sMap[s[right]] += 1;
            right++;
            match = true;
            for (const auto &pair : tMap)
            {
                if (sMap[pair.first] < pair.second)
                {
                    match = false;
                    break;
                }
            }
            if (match) { break; } // find the match substring
        }
        if (!match) { return ""; }

        int left{0};
        while (left < right)
        {
            sMap[s[left]] -= 1;
            left++;

            match = true;
            for (const auto &pair : tMap)
            {
                if (sMap[pair.first] < pair.second)
                {
                    match = false;
                    break;
                }
            }
            if (!match) { break; } // find the shortest unmatched substring
        }
        left--;
        return s.substr(left, right-left);
    }
};

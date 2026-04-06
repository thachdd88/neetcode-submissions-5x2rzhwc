class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> sMap, tMap;
        for (auto ch : s) { sMap[ch] += 1; }
        for (auto ch : t) { tMap[ch] += 1; }
        if (sMap.size() != tMap.size()) { return false; }
        for (const auto &sIter : sMap)
        {
            auto ch = sIter.first;
            auto chCnt = sIter.second;
            if (tMap[ch] != chCnt) { return false; }
        }
        return true; 
    }
};

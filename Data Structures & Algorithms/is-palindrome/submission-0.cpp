class Solution {
public:
    bool isPalindrome(string s) {
        int frontIdx = 0;
        int rearIdx = s.length()-1;
        bool valid = true;
        while (frontIdx < rearIdx)
        {
            char frontCh = static_cast<char>(std::tolower(static_cast<unsigned char>(s[frontIdx])));            
            if (!((('A' <= frontCh) && (frontCh <= 'Z')) ||
            (('a' <= frontCh) && (frontCh <= 'z')) ||
            (('0' <= frontCh) && (frontCh <= '9'))))
            {
                frontIdx++;
                continue;
            }
            
            char rearCh = static_cast<char>(std::tolower(static_cast<unsigned char>(s[rearIdx])));
            if (!((('A' <= rearCh) && (rearCh <= 'Z')) ||
            (('a' <= rearCh) && (rearCh <= 'z')) ||
            (('0' <= rearCh) && (rearCh <= '9'))))
            {
                rearIdx--;
                continue;
            }
            if (frontCh != rearCh) 
            {
                valid = false;
                break;
            }

            frontIdx++;
            rearIdx--;
        }
        return valid;
    }
};

class Solution {
    enum DECODE_STATE
    {
        IDLE, LEN, DELIMITER, MESSAGE
    } ;
public:

    string encode(vector<string>& strs) {
        // strs.clear();
        // strs.push_back("0");
        stringstream ss;
        for (auto &str : strs)
        {
            ss << str.size() << "||" << str;
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        vector<string> res;
        string newStr{};
        int newLen{0};
        int chCnt{0};
        DECODE_STATE state{IDLE};     
        for (int i = 0; i < s.size(); i++)
        {
            char chEvent = s[i];           
            switch (state)         
            {
                case IDLE:
                {
                    newLen = 0;
                    newStr = "";
                    if (('0' <= chEvent) && (chEvent <= '9'))
                    {
                        newLen = chEvent - '0';
                        state = LEN;
                    }
                    break;
                }
                case LEN:
                {
                    if (('0' <= chEvent) && (chEvent <= '9'))
                    {
                        newLen = newLen*10 + (chEvent - '0');
                    }
                    else if (chEvent == '|')
                    {
                        state = DELIMITER;                        
                    }
                    else { /* Error */ }
                    break;
                }
                case DELIMITER:
                {
                    if (chEvent == '|') 
                    {
                        if (newLen == 0)
                        {
                            res.push_back(newStr);
                            state = IDLE; 
                            chCnt = 0;
                        }
                    }
                    else
                    { 
                        newStr = chEvent;
                        chCnt = 1;
                        state = MESSAGE; 

                        if (chCnt == newLen)
                        {
                            res.push_back(newStr);
                            state = IDLE; 
                            chCnt = 0;
                        }
                    }
                    // std::cout << "Mess: " << newStr << std::endl;
                    break;
                }
                case MESSAGE:
                {
                    if (chCnt < newLen)
                    {
                        newStr = newStr + chEvent;
                        chCnt++;
                    }

                    if (chCnt == newLen)
                    {
                        res.push_back(newStr);
                        state = IDLE; 
                        chCnt = 0;
                    }
                    // std::cout << "Decode: " << newStr << " chEvent: " << chEvent << " Cnt: " << chCnt << std::endl; 
                    break;
                }
            }
        }
        // if ((chCnt == newLen)) { res.push_back(newStr); }
        return res;
    }
};

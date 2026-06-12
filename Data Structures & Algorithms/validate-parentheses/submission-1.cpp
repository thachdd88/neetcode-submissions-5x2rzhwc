class Solution {
public:
    bool isValid(string s) {
        vector<char> chStack;
        bool valid = true;
        for (int i = 0; valid && i < s.length(); i++)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                    chStack.push_back(s[i]);
                    break;
                case ')':
                    if (!chStack.empty())
                    {    
                        auto ch = chStack.back();
                        chStack.pop_back();
                        if (ch != '(') { valid = false; }
                    }
                    else { valid = false; }
                    break;
                case ']':
                    if (!chStack.empty())
                    {    
                        auto ch = chStack.back();
                        chStack.pop_back();
                        if (ch != '[') { valid = false; }
                    }
                    else { valid = false; }
                    break;
                case '}':
                    if (!chStack.empty())
                    {    
                        auto ch = chStack.back();
                        chStack.pop_back();
                        if (ch != '{') { valid = false; }
                    }
                    else { valid = false; }
                    break;
            }
        }
        return chStack.empty() && valid;
    }
};

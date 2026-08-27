class Solution {
public:
    bool checkValidString(string s) {
        stack<int> lefts;
        stack<int> stars;
        bool valid = true; 
        for (int i = 0; valid && i < s.length(); i++) {
            switch(s[i]) {
                case '(':
                    lefts.push(i);
                    break;
                case ')':
                    if (lefts.empty())
                    {
                        if (stars.empty()) { valid = false; }
                        else { stars.pop(); }
                    }
                    else { lefts.pop(); }
                    break;
                case '*':
                    stars.push(i);
                    break;
                default:
                    break;
            }
        }
        while (valid && !lefts.empty()) {
            if (stars.empty() || stars.top() < lefts.top()) { valid = false; }
            else { stars.pop(); lefts.pop(); }
        }
        return valid; 
    }
};

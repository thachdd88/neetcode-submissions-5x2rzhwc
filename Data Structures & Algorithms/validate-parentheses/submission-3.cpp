class Solution {
public:
    bool isValid(string s) {
        stack<char> chStk{};
        for (char ch : s) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    chStk.push(ch);
                    break;
                
                case ')':
                    if (chStk.empty() || chStk.top() != '(') { return false; }
                    chStk.pop();
                    break;
                case ']':
                    if (chStk.empty() || chStk.top() != '[') { return false; }
                    chStk.pop();
                    break;
                case '}':
                    if (chStk.empty() || chStk.top() != '{') { return false; }
                    chStk.pop();
                    break;
            }
        }
        return chStk.empty();
    }
};

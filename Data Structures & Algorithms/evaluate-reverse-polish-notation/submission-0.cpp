class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (const auto &token : tokens)
        {
            if (token == "+") 
            {
                int op1 = (!numStack_.empty())? numStack_.top() : 0;
                if (!numStack_.empty()) { numStack_.pop(); }
                
                // printf("%d + %d\n", numStack_.top(), op1);
                if (!numStack_.empty()) { numStack_.top() += op1; }
                else { numStack_.push(op1); }
            }
            else if (token == "-") 
            {
                int op1 = (!numStack_.empty())? numStack_.top() : 0;
                if (!numStack_.empty()) { numStack_.pop(); }
                
                // printf("%d - %d\n", numStack_.top(), op1);
                if (!numStack_.empty()) { numStack_.top() -= op1; }
                else { numStack_.push(-op1); }
            }
            else if (token == "*") 
            {
                int op1 = (!numStack_.empty())? numStack_.top() : 0;
                if (!numStack_.empty()) { numStack_.pop(); }
                
                // printf("%d * %d\n", numStack_.top(), op1);
                if (!numStack_.empty()) { numStack_.top() *= op1; }
                else { numStack_.push(0); }
            }
            else if (token == "/") 
            {
                int op1 = (!numStack_.empty())? numStack_.top() : 0;
                if (!numStack_.empty()) { numStack_.pop(); }
                
                // printf("%d / %d\n", numStack_.top(), op1);
                if (!numStack_.empty()) { numStack_.top() /= op1; }
                else { numStack_.push(0); }
            }
            else
            {
                int operand = stoi(token);
                numStack_.push(operand);
            }
        }
        return numStack_.top();
    }

private:
    stack<int> numStack_{};
};

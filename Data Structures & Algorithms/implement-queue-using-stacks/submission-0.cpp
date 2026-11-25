class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk_[curStk_].push(x);
    }
    
    int pop() {
        int other = (curStk_+1)%2;    
        int top;    
        while (!stk_[curStk_].empty()) {
            top = stk_[curStk_].top();
            stk_[curStk_].pop();
            if (!stk_[curStk_].empty()) { stk_[other].push(top); }
        }
        curStk_ = other;
        other = (curStk_+1)%2;    
        while (!stk_[curStk_].empty()) {
            stk_[other].push(stk_[curStk_].top());
            stk_[curStk_].pop();
        }
        curStk_ = other;
        return top;
    }
    
    int peek() {
        int other = (curStk_+1)%2;    
        int top;    
        while (!stk_[curStk_].empty()) {
            top = stk_[curStk_].top();
            stk_[curStk_].pop();
            stk_[other].push(top);
        }
        curStk_ = other;
        other = (curStk_+1)%2;    
        while (!stk_[curStk_].empty()) {
            stk_[other].push(stk_[curStk_].top());
            stk_[curStk_].pop();
        }
        curStk_ = other;
        return top;
    }
    
    bool empty() {
        return stk_[curStk_].empty();        
    }
private:
    int curStk_{0};
    stack<int> stk_[2];
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
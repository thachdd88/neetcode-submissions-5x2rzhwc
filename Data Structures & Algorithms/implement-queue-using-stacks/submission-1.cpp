class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) { 
        while (!stk_[0].empty()) {
            stk_[1].push(stk_[0].top());
            stk_[0].pop();
        }
        stk_[1].push(x);
        while (!stk_[1].empty()) {
            stk_[0].push(stk_[1].top());
            stk_[1].pop();
        }
    }
    
    int pop() {
        int top = stk_[0].top();
        stk_[0].pop();
        return top;
    }
    
    int peek() {        
        return stk_[0].top();
    }
    
    bool empty() {
        return stk_[0].empty();        
    }
private:
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
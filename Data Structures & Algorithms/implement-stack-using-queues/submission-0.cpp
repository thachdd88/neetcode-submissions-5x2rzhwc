class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        q_[qIdx_].push(x);
    }
    
    int pop() {
        int other = (qIdx_+1) % 2;
        int top{};
        while (!q_[qIdx_].empty()) {
            top = q_[qIdx_].front();
            q_[qIdx_].pop();
            if (!q_[qIdx_].empty()) { q_[other].push(top); }
        }       
        qIdx_ = other; 
        return top;
    }
    
    int top() {
        int other = (qIdx_+1) % 2;
        int top{};
        while (!q_[qIdx_].empty()) {
            top = q_[qIdx_].front();
            q_[qIdx_].pop();
            q_[other].push(top);
        }       
        qIdx_ = other; 
        return top;
    }
    
    bool empty() {
        return q_[qIdx_].empty();
    }
private:
    int qIdx_{0};
    queue<int> q_[2];
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MinStack {
    struct Node
    {
        int value;
        int minValue;
        Node *next{nullptr};
        Node *nextMin{nullptr};
        Node *preMin{nullptr};
    };

public:
    MinStack() {}
    ~MinStack() 
    {
        while (topNode_ != nullptr)
        {
            Node *temp = topNode_;
            topNode_ = topNode_->next;
            delete temp;
        }
    }
    
    void push(int val) 
    {
        Node *newNode = new Node();
        newNode->value = val;
        newNode->next = topNode_;
        if (topNode_ != nullptr) { newNode->minValue = min(newNode->value, topNode_->minValue); }
        else { newNode->minValue = val; }
        topNode_ = newNode;
    }
    
    void pop() {
        if (topNode_ != nullptr)
        {
            Node *temp = topNode_;
            topNode_ = topNode_->next;
            delete temp;
        }
    }
    
    int top() {
        return (topNode_ != nullptr)? topNode_->value : 0;
    }
    
    int getMin() {
        return (topNode_ != nullptr)? topNode_->minValue : 0;
    }

private:
    Node *topNode_{nullptr};
};

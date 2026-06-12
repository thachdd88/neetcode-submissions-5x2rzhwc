class MinStack {
    struct Node
    {
        int value;
        Node *next{nullptr};
        Node *nextMin{nullptr};
        Node *preMin{nullptr};
    };

public:
    MinStack() 
    {
        minNode_ = new Node();
        minNode_->value = 0;
    }
    ~MinStack() 
    {
        while (topNode_ != nullptr)
        {
            Node *temp = topNode_;
            topNode_ = topNode_->next;
            delete temp;
        }
        delete minNode_;
    }
    
    void push(int val) 
    {
        Node *newNode = new Node();
        newNode->value = val;
        newNode->next = topNode_;
        /* TODO add min */
        topNode_ = newNode;
        Node *temp = minNode_;
        while (1)
        {
            if ((temp->nextMin == nullptr) || (temp->nextMin->value > val))
            {
                newNode->nextMin = temp->nextMin;
                if (temp->nextMin != nullptr) { temp->nextMin->preMin = newNode; }
                newNode->preMin = temp;
                temp->nextMin = newNode;

                break;
            }
            temp = temp->nextMin;
        }
    }
    
    void pop() {
        if (topNode_ != nullptr)
        {
            Node *temp = topNode_;
            topNode_ = topNode_->next;

            Node *preMin = temp->preMin;
            Node *nextMin = temp->nextMin;
            if (preMin != nullptr) { preMin->nextMin = nextMin; }
            if (nextMin != nullptr) { nextMin->preMin = preMin; }
            delete temp;
        }
    }
    
    int top() {
        return (topNode_ != nullptr)? topNode_->value : 0;
    }
    
    int getMin() {
        return (minNode_->nextMin != nullptr)? minNode_->nextMin->value : 0;
    }

private:
    Node *topNode_{nullptr};
    Node *minNode_{nullptr};
};

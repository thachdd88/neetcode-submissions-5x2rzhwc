class LRUCache {
    struct Node
    {
        int key;
        int val;
        Node *pre;
        Node *next;
        Node(int key, int val=0, Node *next=nullptr, Node *pre=nullptr)
        : key(key), val(val), pre(pre), next(next) {}
    };
public:
    LRUCache(int capacity)
    : head_(nullptr), tail_(nullptr), capacity_(capacity), size_(0) {}
    
    int get(int key) {
        int val = -1;
        auto nodeIter = keyNode_.find(key);        
        if (nodeIter != keyNode_.end()) 
        {
            printf("Get: %d\n", key);
            Node *node = nodeIter->second;
            val = node->val; 
            moveTop(node);
            // if (node->pre != nullptr)
            // {
            //     printf("Get pre: %d\n", node->pre->key);
            //     node->pre->next = node->next;
            //     if (node->next != nullptr) { node->next->pre = node->pre; }
            //     else { tail_ = node->pre; }
            //     node->next = head_;
            //     node->pre = nullptr;
            //     head_->pre = node;
            //     head_ = node;
            // }
        }

        printList();
        return val;
    }
    
    void put(int key, int value) 
    {
        if (keyNode_.find(key) != keyNode_.end())
        {
            printf("Set: %d\n", key);
            keyNode_[key]->val = value;
            moveTop(keyNode_[key]);
        }
        else
        {
            printf("Put: %d\n", key);
            Node *newNode = new Node(key, value, head_, nullptr);
            head_ = newNode;     
            keyNode_[key] = newNode;
            if (newNode->next == nullptr) { tail_ = newNode; }
            else { newNode->next->pre = newNode; }            
            // printf("Head: %d\n", head_->key);
#if 0
            if (size_ == capacity_) { printf("Erase: %d\n", tail_->key); }
            size_++;
#else
            if (size_ == capacity_)
            {
                Node *temp = tail_;
                tail_ = tail_->pre;
                // printf("Erase: %d, %d\n", temp->key, tail_->pre->key);
                // printf("Erase: %d\n", temp->key);
                // size_++;
                if (tail_ == nullptr) { head_ = nullptr; }
                else { tail_->next = nullptr; }
                keyNode_.erase(temp->key);
                delete temp;
            }
            else { size_++; }
#endif
        }
        printList();
    }

    void moveTop(Node *node)
    {
        if (node->pre != nullptr)
        {
            // printf("Get pre: %d\n", node->pre->key);
            node->pre->next = node->next;
            if (node->next != nullptr) { node->next->pre = node->pre; }
            else { tail_ = node->pre; }
            node->next = head_;
            node->pre = nullptr;
            head_->pre = node;
            head_ = node;
        }
    }
    void printList()
    {
        Node *iter = head_;
        printf("List: ");
        while (iter != nullptr)
        {
            printf("(%d)%d(%d), ", (iter->pre)? iter->pre->key : -1, iter->key, (iter->next)? iter->next->key : -1);
            iter = iter->next;
        }
        printf("\n");
    }

private:
    map<int, Node*> keyNode_;
    Node* head_, *tail_;
    int capacity_;
    int size_;
};

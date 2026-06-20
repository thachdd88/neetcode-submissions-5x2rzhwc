#if 1
class KthLargest 
{
public:
    KthLargest(int k, vector<int>& nums)  
    : k_(k)
    {
        for (auto num : nums) { add(num); }
    }
    int add(int val) 
    {
        minQueue_.push(val);
        if (minQueue_.size() > k_) { minQueue_.pop(); }
        return minQueue_.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> minQueue_;
    int k_;
};
#else
class KthLargest {
    struct ListNode
    {
        int val;
        int cnt{1};
        ListNode *next;
        ListNode(int val, ListNode *next=nullptr) : val(val), next(next) {}
    };
public:
    KthLargest(int k, vector<int>& nums) 
    : k_(k), head(nullptr)
    {
        for (int &num : nums) { insert(num); }
    }
    
    int add(int val)     
    {        
        insert(val);

        ListNode *iter{head};
        int cnt = iter->cnt;
        while (cnt < k_ && iter)
        {
            iter = iter->next;
            cnt += iter->cnt;
        }
        return (iter)? iter->val : -1;
    }
    void insert(int val)
    {
        if (!head) { head = new ListNode(val); }
        else if (head->val < val) 
        {
            ListNode *node = new ListNode(val, head);
            head = node;
        }
        else
        {
            ListNode *iter{head};
            while (iter)
            {
                if (iter->val == val) { iter->cnt++; break; }
                else if (iter->next == nullptr) { iter->next = new ListNode(val); break; } 
                else if (iter->next->val < val)
                {
                    ListNode *node = new ListNode(val, iter->next);
                    iter->next = node;
                    break;
                }
                 { iter = iter->next; }
            }
        }
    }

private:
    ListNode *head;
    int k_;
};
#endif
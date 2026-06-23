class MedianFinder {
public:
    MedianFinder() 
    {        
        // left_.push(1);
        // left_.push(2);
        // right_.push(9);
        // right_.push(10);
        // printQueue(left_);
        // printQueue(right_);
    }
    
    void addNum(int num) 
    {
        if (left_.empty() || num < left_.top()) { left_.push(num); }
        else { right_.push(num); }

        if (right_.size() > left_.size() + 1) 
        {
            int num = right_.top();
            right_.pop();
            left_.push(num);
        }

        if (left_.size() > right_.size() + 1) 
        {
            int num = left_.top();
            left_.pop();
            right_.push(num);
        }
    }
    
    double findMedian() {
        if (left_.size() > right_.size()) { return left_.top(); }
        else if (right_.size() > left_.size()) { return right_.top(); }
        else { return 0.5*left_.top()+0.5*right_.top(); }
    }

    template<typename Compare>
    void printQueue(priority_queue<int, vector<int>, Compare> nums)
    {
        printf("Queue: ");
        while (!nums.empty())
        {
            printf("%d, ", nums.top());
            nums.pop();
        }
        printf("\n");
    }


private:
    priority_queue<int, vector<int>, greater<int>> right_; // min-heap
    priority_queue<int, vector<int>, less<int>> left_; // max-heap
};

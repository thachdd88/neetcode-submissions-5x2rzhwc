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
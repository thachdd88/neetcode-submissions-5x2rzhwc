class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> sQueue;
        for (auto stone : stones) { sQueue.push(stone); }

        while (sQueue.size() > 1)
        {
            int s1 = sQueue.top();
            sQueue.pop();
            int s2 = sQueue.top();
            sQueue.pop();

            sQueue.push(abs(s1-s2));
        }
        int remain = sQueue.top();
        sQueue.pop();
        return remain;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int totalTasks = tasks.size();
        map<char, int> freq;
        for (auto task : tasks) { freq[task] += 1; }        

        auto cmp = [](const pair<char, int> &a, const pair<char, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> tqueue(freq.begin(), freq.end());  
        queue<pair<char, int>> waitList;
        int cycle{0};
        while (!tqueue.empty() || !waitList.empty())
        {
            if (!tqueue.empty()) 
            {
                auto task = tqueue.top();
                tqueue.pop();    
                totalTasks--;

                waitList.push(task);
            }
            else if (totalTasks > 0) { waitList.push({'0', 1}); }

            if (waitList.size() > n || (!waitList.empty() && (totalTasks <= 0) ))
            {
                auto exTask = waitList.front();
                waitList.pop(); cycle++;

                exTask.second--;
                if (exTask.second > 0)
                {
                    tqueue.push(exTask);
                }
            }
        }

        return cycle;
    }
};

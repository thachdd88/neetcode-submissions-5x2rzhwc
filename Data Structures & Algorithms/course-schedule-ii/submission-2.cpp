class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        for (const auto &pre : prerequisites)
        {
            preList[pre[0]].push_back(pre[1]);
        }
        bool valid = true; 
        int label = 1;
        for (int course = 0; valid && course < numCourses; course++)
        {
            if (marks[course] == 0) { valid = labelCourses(course, label++); }
        }
        if (!valid) { cList.clear(); }
        return cList; 
    }
    bool labelCourses(int cIdx, int label)
    {
        if (marks[cIdx] < 0) { return false; }
        else if (marks[cIdx] != 0) { return true; }
        else
        {
            marks[cIdx] = -label;
            bool valid = true; 
            for (int i = 0; valid && i < preList[cIdx].size(); i++) 
            {
                valid = labelCourses(preList[cIdx][i], label);
            }
            if (valid) 
            { 
                marks[cIdx] = label;
                cList.push_back(cIdx); 
            }
            return valid;
        }
    }
private:
    map<int, int> marks{};
    map<int, vector<int>> preList{};
    vector<int> cList{};
};

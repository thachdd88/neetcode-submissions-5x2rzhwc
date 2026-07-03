class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        coursePre = vector<vector<int>>(numCourses, vector<int>());
        for (auto &req : prerequisites) { coursePre[req[0]].push_back(req[1]); }

        status = vector<int>(numCourses, 0);
        bool valid = true;
        for (int course = 0; valid && course < numCourses; course++)
        {
            valid = checkCourse(course);
        }
        return valid; 
    }

    bool checkCourse(int course)
    {
        bool valid = true;
        status[course] = 2;
        for (int i = 0; valid && i < coursePre[course].size(); i++)
        {
            int c = coursePre[course][i];
            if (status[c] == -1 || status[c] == 2) { valid = false; }
            else if (status[c] == 0) { valid = checkCourse(c); }
        }
        status[course] = (valid)? 1 : -1;
        return valid;
    }

private:
    vector<vector<int>> coursePre;    
    vector<int> status;
};

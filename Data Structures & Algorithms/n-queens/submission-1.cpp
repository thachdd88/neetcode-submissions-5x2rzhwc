class Solution {
public:
    vector<vector<string>> outputs;
    vector<vector<string>> solveNQueens(int n) {        
        vector<int> queens(n);
        for (int i = 0; i < n; i++) { queens[i] = i; }

        permute(queens, 0);

        return outputs;
    }

    void permute(vector<int> & queens, int start)
    {
        if ((start == queens.size()) && checkValid(queens))
        {
            outputs.emplace_back(makeOutput(queens));
        }
        for (int i = start; i < queens.size(); i++)
        {
            swap(queens[start], queens[i]);
            permute(queens, start+1);
            swap(queens[i], queens[start]);
        }
    }

    vector<string> makeOutput(const vector<int> &queens)
    {
        vector<string> output;
        for (auto row : queens)
        {
            string qStr = "";
            for (int i = 0; i < queens.size(); i++)
            {
                qStr.append((i == row)? "Q" : ".");
            }
            output.emplace_back(qStr);
        }
        return output;
    }
    bool checkValid(const vector<int> &queens)
    {
        bool valid = true;
        for (int i = 0; valid && i < queens.size()-1; i++)
        {
            for (int j = i+1; valid && j < queens.size(); j++)
            {
                float x = fabs(queens[j] - queens[i]);
                float y = fabs(j - i);
                if (fabs(y/x - 1.0) < 1e-3) { valid = false; }
            }
        }
        return valid;
    }
};

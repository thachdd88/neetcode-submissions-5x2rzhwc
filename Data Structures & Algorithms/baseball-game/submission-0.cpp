class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores{};
        int numScores = 0;
        for (string &op : operations) {
            if (op == "+") {
                int score = scores[numScores-1]+scores[numScores-2];
                scores.push_back(score);
                numScores++;
            }
            else if (op == "D") {
                scores.push_back(scores[numScores-1]*2);
                numScores++;
            }
            else if (op == "C") {
                scores.pop_back();
                numScores--;
            }
            else {
                int score = stoi(op);
                scores.push_back(score);
                numScores++;
            }
        }
        int total = 0;
        for (auto score : scores) { total += score; }
        return total;
    }
};
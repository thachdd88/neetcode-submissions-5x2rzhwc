class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> gp{};
        int start{0}, last{0}, idx{0};
        while (idx < s.length()) {
            char key = s[idx];
            std::size_t found = s.find(key, idx+1);
            if (found != std::string::npos) { last = max(last, (int) found); }
            if (idx == last) {
                gp.push_back(last-start+1);
                start = last+1;            
                last = start;    
                idx = start;
            }
            else { idx++; }
        }
        return gp;
    }
};

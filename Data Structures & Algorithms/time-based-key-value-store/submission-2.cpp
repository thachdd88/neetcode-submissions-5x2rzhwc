class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        data_[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        string res = "";
        const auto &iter = data_.find(key);
        if (iter != data_.end())
        {
            auto &value = iter->second;
            int left{0}, right{static_cast<int>(value.size())-1};
            int cnt = 0;
            while (left <= right && cnt++ < 5)
            {
                int mid = (left+right)/2;
                // printf("%s[%d], %d, %d, %d\n", key.c_str(), timestamp, left, mid, right);

                if (mid == left)
                {
                    if (timestamp >= value[right].first) { res = value[right].second; }
                    else if (timestamp >= value[left].first) { res = value[left].second; }
                    break;
                }
                else if (timestamp >= value[mid].first) { left = mid; }
                else { right = mid; }
            }
            // printf("Final %s[%d], %d, %d\n", key.c_str(), timestamp, left, right);
            
        }
        return res;        
    }

private:
    unordered_map<string, vector<pair<int, string>>> data_;
};

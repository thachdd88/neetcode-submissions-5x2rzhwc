class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        data_[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) 
    {
        string res = "";
        const auto &iter = data_.find(key);
        if (iter != data_.end())
        {
            auto &value_ = iter->second;
            // auto value_ = map<int, string>();            
            for (auto it = value_.rbegin(); it != value_.rend(); ++it)
            {
                // printf("time: %d\n", it->first);
                if (it->first <= timestamp)
                {
                    res = it->second;
                    break;
                }
            }
        }
        return res;        
    }

private:
    unordered_map<string, map<int, string>> data_;
};

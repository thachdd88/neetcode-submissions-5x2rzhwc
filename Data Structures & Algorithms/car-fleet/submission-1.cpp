class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars(position.size());

        for (int i = 0; i < position.size(); i++)
        {
            cars[i].first = target - position[i];
            cars[i].second = static_cast<float>(target - position[i])/speed[i];
        }
        sort(cars.begin(), cars.end());
        int groups{0};
        float lastTime{-1};        
        for (auto &car : cars)
        {
            if (car.second > lastTime)
            {
                groups++;
                lastTime = car.second;
            }
        }
        return groups;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int front = 0;
        int rear = n-1;
        int maxVolume = 0;
        while (front < rear) {
            int volume = (rear-front)*min(heights[front], heights[rear]);
            if (volume > maxVolume) { maxVolume = volume; }
            if (heights[front] <= heights[rear]) { front++; }
            else { rear--; }
        }
        return maxVolume;
    }
};

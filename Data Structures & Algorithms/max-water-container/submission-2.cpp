class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int front = 0;
        int rear = n-1;
        int maxVolume = 0;
        while (front < rear) {
            int h = min(heights[front], heights[rear]);
            int volume = (rear-front)*h;
            if (volume > maxVolume) { maxVolume = volume; }

            while (front < rear && heights[front] <= h) { front++;}
            while (front < rear && heights[rear] <= h) { rear--; }
        }
        return maxVolume;
    }
};

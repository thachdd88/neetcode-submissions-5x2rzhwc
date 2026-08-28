/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxRoom{0};
        priority_queue<int, vector<int>, greater<int>> rooms{};
        sort(intervals.begin(), intervals.end(), [](const Interval &lhs, const Interval &rhs) {
            return lhs.start < rhs.start;
        });
        for (auto &interval : intervals) {
            if (rooms.empty()) {
                rooms.push(interval.end);
            } else {
                while (!rooms.empty() && rooms.top() <= interval.start) { rooms.pop(); }
                rooms.push(interval.end);
            }            
            maxRoom = max(maxRoom, (int) rooms.size());
        }
        return maxRoom;
    }
};

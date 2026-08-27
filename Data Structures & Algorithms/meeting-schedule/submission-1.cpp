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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &lhs, const Interval &rhs) {
            return lhs.start < rhs.start;
        });

        bool valid = true;
        for (int i = 1; valid && i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) { valid = false; }
        }

        return valid;
    }
};

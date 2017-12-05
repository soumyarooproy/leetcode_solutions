// 13 ms, 09/13/2017
// Time  : O(n lg n)
// Space : O(1)
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [] (const Interval& x, const Interval& y) { return x.start < y.start; });
        
        for (int i = 1, n = intervals.size(); i < n; ++i) {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }
};

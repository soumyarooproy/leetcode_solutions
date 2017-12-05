// 13 ms, 09/27/2017
// Time  : O(n lg n)
// Space : O(k), k is the max
// TODO  : Understand the solution below; also, can this be done in O(n) time?
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
using std::priority_queue;
using std::vector;
using std::greater;
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals)
    {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
             [] (const Interval& x, const Interval& y) { return x.start < y.start; });

        priority_queue<int, vector<int>, greater<int>> min_heap;
        int min_rooms = 0;
        for (auto& x : intervals) {
            while (!min_heap.empty() && min_heap.top() <= x.start)
                min_heap.pop();
            min_heap.push(x.end);
            min_rooms = max(min_rooms, static_cast<int>(min_heap.size()));
        }
        return min_rooms;
    }
};
/*----------------------------------------------------------------*/
// More compact solution on leetcode
class Solution {
  
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        if (intervals.empty())
            return 0;
        
        sort(intervals.begin(), intervals.end(),
             [] (const Interval& x, const Interval& y) { return x.start < y.start; });
        
        priority_queue<int, vector<int> , std::greater<int>> q;
        q.push(0);
        for (auto& a : intervals) {
            q.push(a.end);
            if (q.top() <= a.start)
                q.pop();
        }
        return q.size();
    }
};

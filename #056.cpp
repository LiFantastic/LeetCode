/*============================================================
Problem: Merge Intervals
==============================================================
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
============================================================*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool isLess(const Interval& a, const Interval& b) {  
    return a.start < b.start;  
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        vector<Interval> res;
        if (n==0) return res;
        
        sort(intervals.begin(), intervals.end(), isLess);
        Interval current = intervals[0], next;
        
        for (int i=1; i<n; i++) {
            next = intervals[i];
            if (next.start > current.end) {
                res.push_back(current);
                current = next;
            }
            else
                current.end = max(current.end, next.end);
        }
        res.push_back(current);
        
        return res;
    }
};
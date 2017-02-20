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
    static bool comp(const Interval &i1, const Interval &i2) {
        if (i1.start < i2.start) return true;
        else if (i1.start == i2.start) return i1.end < i2.end;
        else return false;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ans;
        Interval temp(intervals[0].start, intervals[0].end);
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (temp.end >= intervals[i].start) {
                temp.end = max(intervals[i].end, temp.end);
            }
            else {
                ans.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
        }
        ans.push_back(temp);
        
        return ans;
    }
};

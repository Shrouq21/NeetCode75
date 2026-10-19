#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = INT_MIN;

  //Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {

        this->start = start;
        this->end = end;
    }
};
 

class Solution {
public:
    static bool comp(Interval a, Interval b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval> intervals) {
        //sort(intervals.begin(), intervals.end(), comp);
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
            });
        int prev = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (!(intervals[i].start >= prev))return false;
            prev = intervals[i].end;
       }
        return true;
    }
};



int main() {
    Solution s;
    Interval i (0, 30);
    Interval i1(5, 10);
    Interval i2(15, 20);
    cout<<s.canAttendMeetings({ i,i1,i2 });

 
}


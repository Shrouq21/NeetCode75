#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = INT_MIN;

  //Definition of Interval:
// class Interval {
// public:
//     int start, end;
//     Interval(int start, int end) {

//         this->start = start;
//         this->end = end;
//     }
// };

class Solution {
public:
    static bool comp(Interval a, Interval b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval> intervals) {
        //sort(intervals.begin(), intervals.end(), comp);
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start ;
            });
        priority_queue<int,vector<int>,greater<int>>queue;
        if (intervals.size() == 0) {
            return 0;
        }
     int m=1;
     queue.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            int minEnding = queue.top();
            if (intervals[i].start < minEnding) {
                ++m;
                queue.push(intervals[i].end);
            }
            else {
                queue.pop();
                queue.push(max(minEnding, intervals[i].end));
            }
            }
           
       
        return m;
    }
};







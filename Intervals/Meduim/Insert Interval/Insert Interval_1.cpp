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
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
        vector<vector<int>>ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] <= intervals[i][1] and intervals[i][0]<=newInterval[1]) 
        {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                continue;
             }
            if (newInterval[0]!=-1 and newInterval[0] < intervals[i][0]) {
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                newInterval[0] = -1;
            }
            else ans.push_back(intervals[i]);
        }
        if (newInterval[0] != -1)ans.push_back(newInterval);
        
        
        return ans;
    }
};



int main() {
    Solution s;
    vector<vector<int>>arr{
        
    };
    s.insert(arr, { 1,3});
 
}


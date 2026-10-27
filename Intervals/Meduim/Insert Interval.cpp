#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = INT_MIN;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
            return a[0] < b[0];
            });


        int st = -1, ed = -1,maxEnd=intervals[0][1];
        for (int i = 1; i < intervals.size() ; i++) {
            if (maxEnd >= intervals[i][0]) {
                if (st == -1)st = i-1;
                ed = i ;
                if (maxEnd < intervals[i][1])
                    maxEnd = intervals[i][1];

            }
            if (st != -1)continue;
            if (maxEnd < intervals[i][1])
                maxEnd = intervals[i][1];

        }

        if (st == -1)return intervals;
        for (int i = 0; i < st; i++)ans.push_back(intervals[i]);
        ans.push_back({ intervals[st][0],maxEnd });
        for (int i = ed+1; i < intervals.size(); i++)ans.push_back(intervals[i]);
        return ans;
    }
};
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
     set<int>mp;
        int total = 0, cnt =0;
        for (auto& i : nums)mp.insert(i);
        int prev = -1; bool start = 0;
        for (auto& i : mp) {
            if (start == 0) { prev = i; start = 1;  }
                if (i == prev + 1)++cnt;
                else cnt = 1;
            total = max(total, cnt);
            prev = i;
        }
        return total;
    }
};
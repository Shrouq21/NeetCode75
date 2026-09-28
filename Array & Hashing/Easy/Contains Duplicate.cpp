#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int>cnt;
        for (int i = 0; i < (int)nums.size(); i++) {
         
            if (cnt[nums[i]])return true;
            cnt[nums[i]]++;
        }
        return false;
    }
};
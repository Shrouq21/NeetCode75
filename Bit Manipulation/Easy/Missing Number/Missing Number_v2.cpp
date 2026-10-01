#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>&nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int cur = 0;
        for (auto i : nums)cur += i;
        return total - cur;
    }
};
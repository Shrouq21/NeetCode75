#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
// to_ulong(),to_ullong((
class Solution {
public:
    int missingNumber(vector<int> nums) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            ans += (i - nums[i]);
     }
        return ans;
    }
};

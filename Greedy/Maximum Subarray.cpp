#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = 1e7;
class Solution {
public:
    int maxSubArray(vector<int> nums) {
        vector<int>prefix(nums.size() );
        prefix[0] = nums[0];
        int maxE = -OO,maxPos=-OO,minPos=OO;
        for (auto i : nums)maxE = max(i, maxE);
        if (nums.size() == 1)return maxE;
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            if (maxPos == -OO)maxPos = i;
            else {
                if (prefix[maxPos] < prefix[i])maxPos = i;
            }
        }
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] < 0 and i < maxPos) {
                if (minPos == OO) { minPos = i; continue; }
                if (prefix[i] < prefix[minPos])minPos = i;
            }
        }
        if (minPos != OO) prefix[maxPos] -= prefix[minPos];
        if (maxE > prefix[maxPos])return maxE;
       
        return prefix[maxPos];
    }
}; // Time :O(N) Memory:O(N)


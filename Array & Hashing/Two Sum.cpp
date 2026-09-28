#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>&nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0, r =nums.size()-1;
        int sum = 0;
        while (l<r) {
            sum = nums[l] + nums[r];
            if (sum > target)
                r--;
            else if (sum == target)return{ l,r };
            else l++;
        }
    }
};



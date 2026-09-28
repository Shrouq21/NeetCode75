#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
        vector<vector<int>> threeSum(vector<int>&nums) {
            vector<int>x;
            int n = nums.size();
            vector<vector<int>>temp;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n-2; i++) {
                if (i != 0 and nums[i] == nums[i - 1])continue;
                int left = i + 1, right = n-1;
                int target = -nums[i] ;
                while (left < right) {
                        if( nums[left]+nums[right]==target){
                            temp.push_back({ nums[i],nums[right],nums[left] });
                            left++; right--;
                            while (left<right
                                and  nums[left] == nums[left - 1] and nums[right] == nums[right + 1])
                            { left++; right--; }
                    }
                    else if (nums[left] + nums[right] < target)left++;
                    else right--;
                }
            }
            return temp;
        }
   

}; // Time: O(N^2) , Memory: O(1)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        vector<vector<int>>bucket(nums.size()+1);
        for (auto& i : nums) {
            freq[i]++;
        }
        for (auto& i : freq) {
            int count = i.first;
            int num = i.second;
            bucket[num].push_back(count);
       }
        vector<int>ans;
        for (int i = bucket.size()-1; i >= 0 ; i--) {
            for (auto nums : bucket[i]) {
                ans.push_back(nums);
                if (ans.size() == k)return ans;
            }
        }
       
    }
};

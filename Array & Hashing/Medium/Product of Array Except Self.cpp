#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
    class Solution {
    public:
        vector<int> productExceptSelf(vector<int>&nums) {
            int result = 1;
           int countzeros = 0;
            vector<int>ans;
            for (auto i : nums) {
                if (i == 0) {
                    countzeros++;
                    continue;
                }
                result *= i;
                
            }
            for (auto i : nums) {
                if (countzeros > 1) {
                    ans.push_back(0);
                    continue;
                }
                if (countzeros == 1) {
                    if (i == 0)ans.push_back(result);
                    else ans.push_back(0);
                }
                else
                    ans.push_back(result / i);  
            }
            return ans;
        }
    };
// Time: O(n)
// Memory: O(n)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = 1e7;
typedef vector<vector<int>>Graph;
class Solution {
public:
    void build(Graph& g, int idx,vector<int>&nums) {
        for (int i = 1; i <= nums[idx]; i++) {
            if (i + idx >= nums.size())break;
            g[idx].push_back(idx + i);
        }
    }
    bool dfs(Graph& g, int start,vector<int>&nums,vector<int>&visited) {
        visited[start] = 1;
        if (start == nums.size() - 1)return true;
        for (auto i : g[start]) {
            if (i!=nums.size()-1 and nums[i] == 0 or visited[i])continue;
            if (dfs(g, i, nums,visited))return true;
       }
        return false;
    }
    bool canJump(vector<int> nums) {
        Graph g(nums.size());
        vector<int>visited(nums.size(),0);
        for (int i = 0; i < nums.size(); i++) {
            build(g, i, nums);
       }
       
        return dfs(g, 0, nums,visited);


    }
};
// Time:O(V+E) Space:O(V+E)



int main() {
    Solution s;
    
    cout << s.canJump({ 3,0,8,2,0,0,1 });
}
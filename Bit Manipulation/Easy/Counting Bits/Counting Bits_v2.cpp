#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for (int i = 1; i <= n; i++) {
            int x = (i >> 1);
            if (i & 1)ans[i] = ans[x]+1; 
            else ans[i] = ans[x];
        }
        return ans;
        
    } 
};

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
       unordered_map<string, vector<string>>connect;
       for (auto& st : strs) {
           int count[26]{};
           for (auto ch : st)count[ch - 'a']++;
           string key{};
           for (int i = 0; i < 26; i++) {
               key += to_string(count[i])+"#";
           }
           connect[key].push_back(st);
        }
       for (auto i : connect) {
           res.push_back(i.second);
       }
        return res;
    }
};

// Time =  O(n* k ) 
// space
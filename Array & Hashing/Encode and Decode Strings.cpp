#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res{};
        stringstream os;
      
            for (auto i : strs) {
                os << i.size();
                os << '#';
                os << i;
                
            }
       
        return os.str();
     
    }
    
    vector<string> decode(string s) {
        

        string word{};
        vector<string>result;
        int idx = 0;
        while (!s.empty()) {
        
            int key = s.find('#');
           idx = stoi(s.substr(0, key));
           word = s.substr(key+1, idx);
            s.erase(0,idx+key+1);
            result.push_back(word);
       }

        return result;

    }

};

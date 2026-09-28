#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int OO = 1000000;

const int  OO = INT_MAX;
class Solution {
public:
	string minWindow(string s, string t) {
		map<char,pair<int,int>>mp; // Max keys=256 = constant
		for (char c : t)mp[c].first++;
		int cnt = mp.size();
		int l = 0, r = 0; 
		int left = 1, right = OO;
		//"OUZODYXAZV"   "XYZ"
		while (r < s.size()) { //O(2n) =O(n)
			if (mp.find(s[r]) != mp.end()) {
				mp[s[r]].second++;
				
				if (mp[s[r]].first == mp[s[r]].second) cnt--;
			}
			++r;
			if (mp.find(s[l]) == mp.end()) {
				++l; continue;
			}
			while(cnt==0 or(l<s.size() and  mp.find(s[l])==mp.end())) {
				if (cnt == 0) { if (r - l + 1 < right - left + 1)right = r, left = l; }
				if (mp.find(s[l]) != mp.end()) {
					mp[s[l]].second--;
					if (mp[s[l]].second < mp[s[l]].first)++cnt;
				}
				
				++l;
		}
		}
		string ans{};
		if(right!=OO)
		for (int i = left; i <right; i++) { // O(m)
			ans += s[i];
		}
		return ans;
	}
}; // O(n) time O(1) memory

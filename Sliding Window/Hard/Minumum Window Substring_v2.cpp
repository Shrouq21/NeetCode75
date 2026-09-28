#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int OO = 1000000;
class Solution {
public:
	string minWindow(string s, string t) {
		int have[123]{};
		int need[123]{};
		int required = t.size();
		for (auto c : t)need[c]++;
		int l = 0, r = 0;
		int lIndex = 0,total = OO;
		while (r < s.size()) {
			if (need[s[r]] > have[s[r]])
				required--;
			have[s[r]]++;

			while (required == 0) {

				if (r - l + 1 < total) {
					lIndex = l;
					total = r - l + 1;
				}
				
				if (need[s[l]] > 0)have[s[l]]--;
				if (have[s[l]] < need[s[l]])required++;
				l++;
			}
			r++;
		}
		if (total == OO)return "";
		return s.substr(lIndex, total);
	}
};


int main() {
	Solution s;
cout<<	s.minWindow("ADOBECODEBANC", "ABC");
	return 0;
}


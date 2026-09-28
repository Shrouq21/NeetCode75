class Solution {
public:
	int lengthOfLongestSubstring(string s) {
	int freq[256]{};
		int l = 0, r = 0;
		int res = 0, curr = 0;
		while (r<s.size()) {
			++curr;
			freq[s[r]]++;
			while (freq[s[r]] > 1) {
				freq[s[l]]--;
				++l;
				curr--;
			}
			r++;
			res = max(curr, res);
		}
		return res;
	}
}; // O(N) time , O(1) memory


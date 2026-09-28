class Solution {
public:
	int characterReplacement(string s, int k) {
		int e ,r,l;
		int freq[91]{}; //constant memory
		for (int i = 0; i < s.size(); i++) {
			freq[s[i]]++;
		}

		int total = 0;
		for (char c = 'A'; c <= 'Z'; ++c) { //constant time
			if (freq[c]) {
				l = 0, r = 0,e=k;
				while (r < s.size()) {
					while ( e ==0 and s[r]!=c) {
					 if(s[l]!=c)
					    ++e;
						++l;
					}
					if (s[r] != c)e--;
					total =max(total, r - l + 1);

					++r;
				}
			}
		}
		return total;
	}
}; // O(N) time O(1) memory

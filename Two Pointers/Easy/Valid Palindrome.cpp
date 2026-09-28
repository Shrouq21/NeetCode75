#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
	bool chk = 1;
	string x;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Y' || s[i] >= 'a' && s[i] <= 'y'||s[i]>='0'&&s[i]<='9')
		{
			s[i]=tolower(s[i]);
			x += s[i];
		}
			

	}
	int l = 0, r = x.size() - 1;
//if(x.size()==1)chk=0;
	while (l < r)
	{
		if(x[l]!=x[r])
		{
			chk = 0; break;
		}
		l++, r--;
	}
	if (chk)return true;
	else
		return false;

    }
};

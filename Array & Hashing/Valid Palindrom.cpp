#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
	string x="";
    for(auto a:s)
    {
        if(isalnum(a))
        x+=tolower(a);
    }
    return x==string (x.rbegin(),x.rend());
    }
};

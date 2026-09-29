#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>open;
        for (auto& i : s) {
            if (i == '(' or i == '[' or i == '{')open.push(i);
            else {
                if (open.empty())return false;
                char top = open.top();
                if (i == ')' and top != '('
                    or i == '}' and top != '{'
                    or i == ']' and top != '['
                    )
                    return false;
                open.pop();
            }
        }
        if (!open.empty())return false;
        return true;
    }
};
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        bitset<32>b = n;
        return b.count();
    }
};
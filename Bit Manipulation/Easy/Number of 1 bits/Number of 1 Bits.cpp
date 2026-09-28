#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1)++sum;
        }
        return sum;
    }
};

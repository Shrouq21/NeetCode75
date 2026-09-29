#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
// to_ulong(),to_ullong((
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int num = 0;
        for (int i = 31; i>=0; i--) {
            
            num += (((n>>(31-i))&1)  * (1<<i));
       }
        return num;
    }
};

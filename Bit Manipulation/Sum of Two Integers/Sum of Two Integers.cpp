#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
// to_ulong(),to_ullong((
class Solution {
public:
    int getSum(int a, int b) {
        int xOr = 1, andOp = 1;
        while (b!= 0) {
            xOr = a ^ b;
            andOp = a & b;
            andOp <<= 1;
            a = xOr;
            b = andOp;

        }
        return a;
    }
};

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
   
        int maxArea(vector<int> &heights) {
            int left = 0, right = heights.size() - 1;

            int MArea = -1;
            while (left < right) {
                int a = heights[left], b = heights[right];
                int Area = (right - left) * min(a, b);
                MArea = max(MArea,Area);
                if (a < b)left++;
                else right--;
           }
            return MArea;
        }
  


}; 
// Time: O(N) , Memory: O(1)
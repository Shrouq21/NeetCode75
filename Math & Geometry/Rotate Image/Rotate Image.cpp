#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = INT_MIN;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();//3
      map<pair<int, int>, int>visited;
        for (int col = 0; col < matrix.size(); col++) { //col=0
            for (int row = matrix.size()-1; row >= 0; row--) { //row=2
                pair<int, int>cur = { row,col };//{2,0}
                if (!visited.count(cur)) {
                    int num = matrix[cur.first][cur.second];//{1,0}
                    int nextNum = OO;
                    while (true) {
                        visited[cur]++;
                        pair<int, int>move = { cur.second,n-cur.first-1 };//{2,0}
                        if (nextNum == OO)matrix[cur.first][ cur.second] = OO;
                        nextNum = matrix[move.first][move.second];//9
                        matrix[move.first][move.second] = num;
                        num = nextNum;//9
                        cur = move; //cur={2,2}
                        if (num == OO) break;

                        

                    }
                }
            }
        }
    }
};




int main() {
    Solution s;
    
    vector<vector<int>>matrix{ {1,2,3},{4,5,6},{7,8,9} };
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
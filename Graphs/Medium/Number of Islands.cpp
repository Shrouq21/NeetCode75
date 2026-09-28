#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int OO = 1000000;
int row[] = { 0,0,1,-1 };
int col[] = { 1,-1,0,0 };
class Solution {
public:

    bool isValid(int row, int col, int rows, int cols)
    {
        return(row >= 0 and row < rows and col >= 0 and col < cols);
    }
    void dfs(vector<vector<char>>&g,vector<vector<int>>&visited,int stRow,int stCol) {
        if (g[stRow][stCol] == '0')return;
        visited[stRow][stCol] = 1;

        for (int i = 0; i < 4; i++) {
            int r = row[i] + stRow;
            int c = col[i] + stCol;
            if (isValid(r, c, g.size(), g[0].size()) and !visited[r][c])
                dfs(g, visited, r, c);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size()));// O(RC) Memory
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!visited[i][j] and grid[i][j]!='0') {
                    ++cnt;
                    dfs(grid, visited,i,j);
                }
            }
        }
        return cnt;
    }
}; // Memory:O(RC)     Time:O(RC)
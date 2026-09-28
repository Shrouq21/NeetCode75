#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int rd[]{ 0,0,1,-1 };
int cd[]{ 1,-1,0,0 };
class Solution {
public:
	struct cell {
		int r, c;
	};
	bool isValid(cell c, int rows, int columns) {
		return(c.r >= 0 and c.r < rows and c.c >= 0 and c.c <columns);
	}
	void bfs(vector<vector<int>>& matrix, vector<cell>& pa, vector<vector<bool>>& visited) {
		int r = matrix.size(), c = matrix[0].size();
		queue<cell>qu;
		// pa=>memory(R+C)
		for (auto c : pa) { // time => (R+C)
			qu.push(c);//parent o(1)
			visited[c.r][c.c] = 1;
		}
		for (int sz = qu.size(); !qu.empty(); sz=qu.size()) {
			while (sz--) { 
				// Each cell is processed at most once: O(R*C)
               // For each cell, we check 4 directions: O(4)
              // Total: O(R*C)
				//The 4 is a constant, so we remove it
				cell cur = qu.front();
				qu.pop();
				for (int i = 0; i < 4; i++) {
					cell x = { cur.r + rd[i],cur.c + cd[i] };
					if (!isValid(x, r, c) or visited[x.r][x.c] or matrix[cur.r][cur.c] > matrix[x.r][x.c])continue;
					qu.push(x);
					visited[x.r][x.c] = 1;
				}

			}
		}
		// max qu size=> O(R*C)
	}
		vector<vector<int>> pacificAtlantic(vector<vector<int>>&matrix) {
			int rows = matrix.size(), columns = matrix[0].size();
			vector<cell>pacific, atlantic;

			// memory:o(RC)
			vector<vector<bool>>pacific_visited(matrix.size(), vector<bool>(matrix[0].size(),false)); 
			vector<vector<bool>>Atlantic_visited(matrix.size(), vector<bool>(matrix[0].size(),false));


			// time=memory=O(C)
			for (int i = 0; i < columns; i++) {
				pacific.push_back({ 0,i }); // memory=time=O(1) per insertion
				atlantic.push_back({ rows - 1,i });
			}


			// time=memory=O(R)
			for (int i = 0; i < rows; i++) {
				if(i!=0)
				pacific.push_back({ i,0 });
				atlantic.push_back({ i,columns - 1 });
			}


			// Each BFS: O(R*C)
           // Two BFS calls: O(2*R*C) = O(R*C)
			bfs(matrix, pacific, pacific_visited);
			bfs(matrix, atlantic, Atlantic_visited);

			vector<vector<int>>ans;
			// time =>O(RC)
			for (int i = 0; i < pacific_visited.size(); i++) {
				for (int j = 0; j < pacific_visited[i].size(); j++) {
					if (pacific_visited[i][j] and Atlantic_visited[i][j])ans.push_back({ i,j });
				}
			}
			return ans;
		}

};
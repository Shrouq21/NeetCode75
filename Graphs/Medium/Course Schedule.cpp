#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int OO = 1000000;typedef vector<vector<int>>Graph;
class Solution {
public:
	void adjacency_list(Graph &g,int from ,int to){
		g[from].push_back(to);
	}
	void dfs(Graph& g,int parent, bool& valid,vector<int>&visited) {
		
		visited[parent] = 1;//start
		for (auto c : g[parent]) {
			if (visited[c]==1) { 
				valid = false; 
				return;
			}
			if (visited[c] == 2)continue;
			dfs(g, c, valid, visited);
		}
		visited[parent] = 2; //end of dfs

	}
	bool canFinish(int numCourses, vector<vector<int>>prerequisites) {
		Graph g(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			adjacency_list(g, prerequisites[i][1], prerequisites[i][0]);	
	}
		vector<int>visited(numCourses, 0);
		for (int i = 0; i < numCourses; i++) { 
			if (visited[i] )continue;
			bool valid = true;
			dfs(g, i, valid,visited);
			if (!valid )return false;
		}
		return true;
	}
	
}; // O(E+V) time , O(E+V) memory
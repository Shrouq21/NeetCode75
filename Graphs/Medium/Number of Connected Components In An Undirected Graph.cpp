#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef unordered_map<int, vector<int>>Graph;
class Solution {
public:
	void dfs(int start, Graph&graph, unordered_set<int>& visited) {
		visited.insert(start);
		for (int i = 0; i < graph[start].size(); i++) {
			if (!visited.count(graph[start][i]))dfs(graph[start][i], graph, visited);
		}
	}
	void build(Graph&graph,vector<vector<int>>& edges) {
		for (int i = 0; i < edges.size(); i++) {
				int from = edges[i][0];
				int to = edges[i][1];
				graph[from].push_back(to);
				graph[to].push_back(from);
		}
	}
	int countComponents(int n, vector<vector<int>>& edges) {
		Graph graph;
		unordered_set<int>visited;
		int count = 0;
		build(graph, edges);
		for(int i=0;i<n;i++){
			if (!visited.count(i)) {
				count++;
				dfs(i, graph, visited);
			}
		}
		return count;
	}
};
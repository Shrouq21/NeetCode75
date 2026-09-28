#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
   
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)return false;
        vector<vector<int>>Graph(n);
        for (int i = 0; i < edges.size(); i++) {
            Graph[edges[i][0]].push_back(edges[i][1]);
            Graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,-1),parent(n,-1);
        queue<int >qu;

        visited[0] = 0;
        qu.push(0);
        for (int level = 1, sz = 1; !qu.empty(); level++, sz = qu.size()) {
            while (sz--) {
                int cur = qu.front();
                qu.pop();
                for (auto neighbor : Graph[cur]) {
                    if (visited[neighbor]==-1) {
                        visited[neighbor] = level;
                        qu.push(neighbor);
                        parent[neighbor] = cur;
                    }
                    else if (parent[cur] != neighbor) //cycle 
                        return false;
                    

                }
            }
        }
        for (int i = 0; i < n; i++) { //subgraph
            if (visited[i] == -1)return false;
        }
        return true;
    }

};

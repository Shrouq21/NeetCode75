#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//Definition for a Node.
// class Node {
// public:
//    int val;
//    vector<Node*> neighbors;
//    Node() {
//        val = 0;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val) {
//        val = _val;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val, vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
// };


class Solution {
public:
    unordered_map<Node*, Node*>mp;
   Node* dfs(Node*node,unordered_map<Node*, Node*>&mp) {
       if (mp.count(node)) {
           return mp[node];
       }
       Node* deepCopy = new Node(node->val);
       mp[node] = deepCopy;
       for (auto neighbor : node->neighbors) {
           deepCopy->neighbors.push_back(dfs(neighbor,mp));
       }
       return deepCopy;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return node;
       return dfs(node,mp);
    }
}; //Time:O(E+V), Space:O(V), Auxiliary Space:O(E+V)
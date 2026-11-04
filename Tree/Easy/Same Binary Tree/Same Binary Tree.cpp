#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = -10000;
class Solution {
public:
    void BinaryTree( TreeNode* root,vector<int>&nodes) {

        if (!root) {
            nodes.push_back(OO);
            return;
        }
        nodes.push_back(root->val);
        BinaryTree(root->left, nodes);
        BinaryTree(root->right, nodes);
       
    }

   
        bool isSameTree(TreeNode* p, TreeNode* q) {
            vector<int>pNodes, qNodes;
            BinaryTree(p, pNodes);
            BinaryTree(q, qNodes);
            if (pNodes.size() != qNodes.size())return false;
            for (int i = 0; i < pNodes.size(); i++) {
                if (pNodes[i] != qNodes[i])return false;
            }
            return true;

        }
   
};
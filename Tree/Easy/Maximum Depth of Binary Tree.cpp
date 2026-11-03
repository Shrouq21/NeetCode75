#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = INT_MIN;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    /*TreeNode* root{};*/
    //void add(vector<int>values) {
    //    TreeNode* cur = root;
    //    for (int i = 0; i < values.size(); i++) {
    //        if(!cur->left){
    //            cur->left = new TreeNode(values[i]);

    //            cur = cur->left;
    //        }
    //        else {
    //            cur->right = new TreeNode(values[i]);
    //            cur = cur->right;
    //        }
    //    }
    //}

    int BinaryTree( TreeNode* root) {
        if (!root)return 0;
        return max(BinaryTree(root->right)+1, BinaryTree(root->left)+1);
    
           
       
    }

    int maxDepth(TreeNode* root) {
     return BinaryTree(root);
     
    }
};


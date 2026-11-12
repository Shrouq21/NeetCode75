//https://neetcode.io/problems/path-sum/question

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
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
    bool Rec(TreeNode* root,int cur, int targetSum) {
        if (!root) {
            return false;
       }
        cur += root->val;
        if (!root->left and !root->right)//leaf

            return cur == targetSum;
        
        return Rec(root->left,cur, targetSum) or Rec(root->right, cur , targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int cur = 0;
       return Rec(root,cur, targetSum);
    }
};
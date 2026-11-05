#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = -10000;
struct TreeNode {
    int val;
    TreeNode* left{};
    TreeNode* right{};
    TreeNode(int val):val(val){}
};

class Solution {
public:
    bool BinaryTree( TreeNode* pRoot,TreeNode*qRoot) {
        if (!pRoot or !qRoot) {
            return ( !pRoot and !qRoot);
        }
        if (pRoot->val != qRoot->val) return false;
       
        
       return BinaryTree(pRoot->left, qRoot->left)and BinaryTree(pRoot->right, qRoot->right);
       
    }

    bool traverse(TreeNode* root, TreeNode* subRoot) {
        if (!root)return false;
        return BinaryTree(root, subRoot)or
              traverse(root->left, subRoot) or traverse(root->right, subRoot);
      
     }
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (!subRoot)return true;
            if (!root)return false;
            return traverse(root, subRoot);


        }
    };
//Time: O(n × m) because we may compare the subtree at every node.
// Space: O(n + m) because we count the maximum simultaneously active recursion frames.

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = -10000;
class Solution {
public:
    void BinaryTree( TreeNode* pRoot,TreeNode*qRoot,bool&chk) {
        if (!pRoot or !qRoot) {
            if (!pRoot and qRoot or pRoot and !qRoot)chk = false;
            return;
        }
        if (pRoot->val != qRoot->val) chk = false;
       
        
        BinaryTree(pRoot->left, qRoot->left,chk);
        BinaryTree(pRoot->right, qRoot->right,chk);
       
    }

   
        bool isSameTree(TreeNode* p, TreeNode* q) {
            bool chk = 1;
            BinaryTree(p, q, chk);
            return chk;

        }
   
};
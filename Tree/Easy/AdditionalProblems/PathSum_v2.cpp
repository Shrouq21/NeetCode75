#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = -10000;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:

    bool check(TreeNode* node) {
        return(!node->left and !node->right);
    }
    bool Rec(TreeNode* root,int cur, int targetSum) {
        if (!root) {
            return false;
       }
        if (check(root) and targetSum == root->val)return true;

            
        
        return Rec(root->left,cur, targetSum-root->val) or Rec(root->right, cur , targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int cur = 0;
       return Rec(root,cur, targetSum);
    }
}; // time :O(N) , Memory:O(N) Skewed, O(log N) Balanced

        int main() {
          
            TreeNode*n=new TreeNode(1);
            n->left = new TreeNode(2);
            n->right = new TreeNode(3);
            Solution s; s.hasPathSum(n, 3);
            


}

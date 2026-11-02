#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = INT_MIN;
// struct TreeNode {
//     int value;
//     TreeNode* left{};
//     TreeNode* right{};
//     TreeNode(int val):value(val){}
// };

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
  void swapValues(TreeNode* root) {
        if (!root)return;
            swap(root->left, root->right);
        swapValues(root->left);
        swapValues(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        swapNodes(root);
        return root;
    }
};
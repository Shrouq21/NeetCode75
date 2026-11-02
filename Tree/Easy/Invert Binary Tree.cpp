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

    void swapNodes(TreeNode* root) {
        if (!root)return;
        if (root->left or root->right) {
            swap(root->left, root->right);
        }
        swapNodes(root->left);
        swapNodes(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        swapNodes(root);
        return root;
    }
};
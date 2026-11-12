#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
const int OO = -10000;
struct Node {
    int val;
    Node* left{}, *right{};
    Node(int val):val(val){}
 
};
struct BinaryTree {
    Node* root{};
    BinaryTree(int val) {
        root = new Node(val);
    }

   

    void add(vector<int>nodes, vector<char>directions) {
        Node* r = root;
        assert(nodes.size() == directions.size());
        for (int i = 0; i < nodes.size(); i++)
        {
            if (directions[i] == 'L') {
                if (!r->left)
                    r->left = new Node(nodes[i]);
                else
                    assert(r->left->val == nodes[i]);
                r = r->left;
            }
            else {
                if (!r->right)
                    r->right = new Node(nodes[i]);
                else
                    assert(r->right->val == nodes[i]);
                r = r->right;

            }
        }
    }
};

class Solution {
public:
    int rec(Node* root) {
        if (!root)return INT_MIN;
        int maxLeft = rec(root->left);
        int maxRight = rec(root->right);
        return max(root->val,max(maxLeft, maxRight));
    }
    int maxValue(Node*node) {
        return rec(node);
    }
    };
//Time: O(n ) 
// Space: O(n) 




        int main() {
            BinaryTree tree(1);
            tree.add({ 2,3,7 }, { 'L','L','L' });
            cout << Solution().maxValue(tree.root) << endl;
            tree.add({ 2,4,8 }, { 'L','L','R' });
            cout << Solution().maxValue(tree.root)<<endl;
            tree.add({ 2,5,9 }, { 'L','R','R' });
            cout << Solution().maxValue(tree.root)<<endl;
            tree.add({ 3,6,10 }, { 'R','R','L' });
            cout << Solution().maxValue(tree.root)<<endl;


}

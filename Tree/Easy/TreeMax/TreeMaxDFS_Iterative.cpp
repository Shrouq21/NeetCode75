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
    int dfsIterative(Node* root) {
        stack<Node*>nodes;

        nodes.push(root);
        int maxNode = INT_MIN;
        while (!nodes.empty()) {
            Node* cur = nodes.top();
            nodes.pop();
            maxNode = max(maxNode, cur->val);
            if (cur->right)nodes.push(cur->right);
            if (cur->left)nodes.push(cur->left);
            
        }
        return maxNode;
    }
    int maxValue(Node*node) {

       return dfsIterative(node);
    }
    };
//Time: O(n) 
// Space: O(h)=o(log n) 
        int main() {
            BinaryTree tree(1);
        /*    tree.add({ 2,3,7 }, { 'L','L','L' });
            cout << Solution().maxValue(tree.root) << endl;*/
            tree.add({ 2,3,8 }, { 'L','L','R' });
            cout << Solution().maxValue(tree.root)<<endl;
            /*tree.add({ 2,5,9 }, { 'L','R','R' });
            cout << Solution().maxValue(tree.root)<<endl;
            tree.add({ 3,6,10 }, { 'R','R','L' });
            cout << Solution().maxValue(tree.root)<<endl;*/


}

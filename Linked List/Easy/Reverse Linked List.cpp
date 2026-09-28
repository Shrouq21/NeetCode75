#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<ListNode*>List;
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        for(ListNode*node=head;node;node=node->next)
        List.push_back(node);
      
       for (int i = List.size()-1; i >=0; i--) {
           if (i == 0)List[i]->next = nullptr;
           else
           List[i]->next = List[i -1];
       }
        return List.back();
    }
};

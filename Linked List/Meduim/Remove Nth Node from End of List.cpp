#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        ListNode*temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        ListNode*prev=head;
        ListNode*curr=head;
        int i=0,j=size-n;
        if(j==0) {return head->next;}
for(int i=0;i<size-n;i++){
    prev=curr;
            curr=curr->next; 
}
        prev->next=curr->next;
        return head;
    }
};

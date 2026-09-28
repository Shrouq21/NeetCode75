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

      ListNode*getMiddle(ListNode* head) {
          ListNode* s{head}, * f{head};
          while (f and f->next) {
              f = f->next->next;
              s = s->next;
          }
          return s;
      }
      ListNode* flip(ListNode* Node) {
          ListNode* prev{}, *next{}, *cur{Node};
          while (cur) {
              next = cur->next;
              cur->next = prev;
              prev = cur;
              cur = next;
          }
          return prev;
      }
      void reorderList(ListNode* head) {
          ListNode * cur{}, * n{},*next_cur,*next_n;

          ListNode* middle = getMiddle(head);
       n =flip(middle->next);
          middle->next = nullptr;
          cur = head;
          while (n) {
              next_cur = cur->next;
              next_n = n->next;
              cur->next = n;
              n->next = next_cur;
              cur = next_cur;
              n = next_n;
              

          }

      }
  };


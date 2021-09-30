#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinal = new ListNode(-1, head);
        ListNode* pred = sentinal;
        
        while(head != NULL){
            if(head->next != NULL && head->val == head->next->val){
                while(head->next != NULL && head->val == head->next->val){
                    head = head->next;
                }
                pred->next = head->next;
            }
            else {
                pred = pred->next;
            }
            head = head->next;
        }
        return sentinal->next;
    }
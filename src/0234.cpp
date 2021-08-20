#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    if(!head || !head->next){
        return true;
    }
    
    ListNode* slow=head, *fast=head;
    
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow=slow->next;
    while(slow){
        if(slow->val != head->val){
            return false;
        }
        slow=slow->next;
        head=head->next;
    }
    return true;
}

ListNode* reverse (ListNode* head){
    ListNode* prev= NULL, *next;
    
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
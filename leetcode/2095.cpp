
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* headnode = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* cur = slow->next->next;
        ListNode* del = slow->next;
        del->next = NULL;
        slow->next = cur;
        
        return headnode;
    }
};
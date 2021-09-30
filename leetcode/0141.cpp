#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (!head)
    return false;

	ListNode* fast = head;
	ListNode* slow = head;

	while (slow!=NULL && fast!=NULL && fast->next!=NULL) {
		
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast)
			return true;
	}
	return false;
}
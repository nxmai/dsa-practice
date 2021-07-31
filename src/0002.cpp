#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode((l1->val+l2->val) % 10);
	ListNode* t = res;

	int rem = (l1->val + l2->val) / 10;
	l1=l1->next;
	l2=l2->next;
	
	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL) {
			ListNode* tmp = new ListNode((l2->val + rem) % 10);
			rem = (l2->val + rem) / 10;
			t->next = tmp;
			t = t->next;
			l2 = l2->next;
		}
		else if (l2 == NULL) {
			ListNode* tmp = new ListNode((l1->val + rem) % 10);
			rem = (l1->val + rem) / 10;
			t->next = tmp;
			t = t->next;
			l1 = l1->next;
		}
		else
		{
			ListNode* tmp = new ListNode((l2->val + rem +l1->val) % 10);
			rem = (l2->val + rem + l1->val) / 10;
			t->next = tmp;
			t = t->next;
			l2 = l2->next;
			l1 = l1->next;
		}
	}
    if (rem != 0) {
	    ListNode* tmp = new ListNode(rem);
	    t->next = tmp;
		t = t->next;
	}
	return res;
}
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insert(ListNode* root, int key) {
	if (!root)
		return new ListNode(key);

	root->next = insert(root->next, key);
	return root;
}

/*check if there is a cycle in a linked list
use floy cycle algorithms
use a fast pointer and slow pointer
move one for slow pointer and two for fast pointer
if a pointer is null -> false
if value of fast pointer == slow pointer => true
*/
bool hasCycle(ListNode* head) {
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

void output(ListNode* root) {
	if (!root)
		return;
	cout << root->val;
	output(root->next);
}

int main() {
	ListNode* root = NULL;
	root = insert(root, 1);
	root = insert(root, 0);
	//root = insert(root, -8);
	//root = insert(root, 5);

	output(root);
	cout << hasCycle(root);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* insert(ListNode* root, int key) {
	if (!root)
		return new ListNode(key);

	root->next = insert(root->next, key);
	return root;
}
    
ListNode* swapNodes(ListNode* head, int k) {
    vector<int> vt;
    while(head!=NULL){
        vt.push_back(head->val);
        head=head->next;
    }
    
    int tmp=vt[k-1];
    vt[k-1]=vt[vt.size()-k];
    vt[vt.size()-k]=tmp;
    
    ListNode* root = new ListNode(vt[0]);
    ListNode* res = root;
    
    for(int i=1;i<vt.size();i++){
        ListNode* tmp = new ListNode(vt[i]);
        root->next = tmp;
        root = root->next;
    }
    
    return res;
}
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* middleNode(ListNode* head) {
    ListNode* cur = head;

    int n = 1;
    while (cur->next != NULL) {
        cur = cur->next;
        n++;
    }   

    int i;
    if (n % 2 == 1)
        i = (n+1)/2;
    else
        i = n / 2 + 1;

    cur = head;
    while (i != 1)
    {
        cur = cur->next;
        i--;
    }

    return cur;
}
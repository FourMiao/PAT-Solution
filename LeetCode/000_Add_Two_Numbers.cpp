#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500 + 10;
const int INF = 1000000000 + 7;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, val = 0;
		ListNode *ans = NULL, *head = NULL;
		bool isHead = 1;
		
		while (l1 != NULL || l2 != NULL) {

			int val1 = 0, val2 = 0;
			if (l1 != NULL) {
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				val2 = l2->val;
				l2 = l2->next;
			}

			val = (val1 + val2 + carry) % 10;
			carry = (val1 + val2 + carry) / 10;
			if (isHead) {
				ListNode *tmp = new ListNode(val);
				ans = tmp;
				head = ans;
				isHead = 0;
			} else {
				ListNode *tmp = new ListNode(val);
				ans->next = tmp;
				ans = ans->next;
			}
		}
		if (carry) {
			ListNode *tmp = new ListNode(carry);
			ans->next = tmp;
			ans = ans->next;
		}
		return head;
    }
};

int main() {
	int num1[] = {2, 4, 3};
	int num2[] = {5, 6, 4};
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	ListNode *head1, *head2;
	
	head1 = l1; head2 = l2;

	for (int i = 0; i < 3; ++i) {
		ListNode *t1 = new ListNode(num1[i]);
		ListNode *t2 = new ListNode(num2[i]);
		printf("%d %d\n", t1->val, t2->val);
		l1->next = t1;
		l2->next = t2;
		l1 = l1->next;
		l2 = l2->next;
	}

	head1 = head1->next;
	head2 = head2->next;

	Solution t;
	ListNode *head = t.addTwoNumbers(head1, head2);
	while(head != NULL) {
		printf("%d\n", head->val);
		head = head->next;
	}

	return 0;
}
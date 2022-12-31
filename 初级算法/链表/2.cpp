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
//双指针
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode*dummy = new ListNode(0, head), *slow = dummy, *fast = head;
		while (n--)
			fast = fast->next;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		ListNode*tmp = dummy->next;
		delete dummy;
		return tmp;
	}
};

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
//栈
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		stack<ListNode*>s;
		ListNode*dummy = new ListNode(0, head), *cur = dummy, *prev;
		while (cur)
		{
			s.push(cur);
			cur = cur->next;
		}
		while (n--)
			s.pop();
		prev = s.top();
		prev->next = prev->next->next;
		ListNode*res = dummy->next;
		delete dummy;
		return res;
	}
};

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
//计数法
class Solution {
public:
	int ListLength(ListNode*l)
	{
		int cnt = 0;
		while (l)
		{
			l = l->next;
			cnt++;
		}
		return cnt;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = ListLength(head);
		ListNode*dummy = new ListNode(0, head), *cur = dummy;
		for (int i = 0; i < len - n; i++)
			cur = cur->next;
		cur->next = cur->next->next;
		ListNode*res = dummy->next;
		delete dummy;
		return res;
	}
};
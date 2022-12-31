/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode*fast = head, *slow = head;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//¹þÏ£±í
class Solution {
public:
	bool hasCycle(ListNode *head) {
		unordered_map<ListNode*, int>m;
		while (head)
		{
			if (m.count(head))
				return true;
			else
				m[head]++;
			head = head->next;
		}
		return false;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		unordered_map<ListNode*, int>m;
		while (head)
		{
			if (m.count(head))
				return head;
			else
				m[head]++;
			head = head->next;
		}
		return nullptr;
	}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {
				ListNode *ptr = head;
				while (ptr != slow)
				{
					ptr = ptr->next;
					slow = slow->next;
				}
				return ptr;
			}
		}
		return nullptr;
	}
};

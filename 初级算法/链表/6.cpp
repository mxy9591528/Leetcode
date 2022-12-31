/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//¿ìÂýÕë
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head || !head->next)
			return false;
		ListNode*fast = head->next, *slow = head;
		while (fast != slow)
		{
			if (!fast || !fast->next)
				return false;
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
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
		unordered_set<ListNode*>s;
		while (head)
		{
			if (s.count(head))
				return true;
			s.insert(head);
			head = head->next;
		}
		return false;
	}
};
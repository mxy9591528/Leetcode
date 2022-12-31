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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		stack<ListNode*>s;
		while (list1&&list2)
		{
			if (list1->val < list2->val)
			{
				s.push(list1);
				list1 = list1->next;
			}
			else
			{
				s.push(list2);
				list2 = list2->next;
			}
		}
		ListNode*pre = list1 ? list1 : list2;//直接追加
		while (!s.empty())
		{
			s.top()->next = pre;
			pre = s.top();
			s.pop();
		}
		return pre;
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
//递归
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1 || !list2)
			return list1 ? list1 : list2;
		else if (list1->val < list2->val)
		{
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
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
//迭代
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode*pHead = new ListNode(-1), *pre = pHead;
		while (list1&&list2)
		{
			if (list1->val < list2->val)
			{
				pre->next = list1;
				list1 = list1->next;
			}
			else
			{
				pre->next = list2;
				list2 = list2->next;
			}
			pre = pre->next;
		}
		pre->next = list1 ? list1 : list2;
		ListNode*res = pHead->next;
		delete pHead;
		return res;
	}
};
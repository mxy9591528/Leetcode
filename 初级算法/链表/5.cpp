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
//��Ϊ�����Ľⷨ
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
	ListNode*reverse(ListNode*l)
	{
		if (!l || !l->next)
			return l;
		ListNode*newHead = reverse(l->next);
		l->next->next = l;
		l->next = NULL;
		return newHead;
	}
	bool isPalindrome(ListNode* head) {
		int len = ListLength(head);
		if (len == 0 || len == 1)
			return true;;
		ListNode*fast = head;
		for (int i = 0; i < (len + 1) / 2; i++)
			fast = fast->next;
		fast = reverse(fast);
		while (fast)
		{
			if (head->val != fast->val)
				return false;
			head = head->next;
			fast = fast->next;
		}
		return true;
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
//ת����
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int>v;
		while (head)
		{
			v.emplace_back(head->val);
			head = head->next;
		}
		int len = v.size();
		for (int i = 0; i < len / 2; i++)
		{
			if (v[i] != v[len - i - 1])
				return false;
		}
		return true;
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
//������
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		ListNode*endstart = reverse(endnode(head));
		while (endstart)
		{
			if (head->val != endstart->val)
				return false;
			endstart = endstart->next;
			head = head->next;
		}
		return true;
	}
	ListNode*endnode(ListNode*l)
	{
		ListNode*slow = l, *fast = l;
		while (fast->next&&fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow->next;
	}
	ListNode*reverse(ListNode*l)
	{
		ListNode*pre = NULL;
		while (l)
		{
			ListNode*next = l->next;
			l->next = pre;
			pre = l;
			l = next;
		}
		return pre;
	}
};

//���������
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *slow = head, *fast = head, *prev = nullptr;
		while (fast&& fast->next) {
			fast = fast->next->next;
			ListNode* temp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = temp;
		}//�߱���������
		if (fast) //��ż���жϣ�����Ϊ��Ϊż�����������һλ
			slow = slow->next;
		while (slow) {
			if (slow->val != prev->val)
				return false;
			prev = prev->next;
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//ջ��������
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		ListNode*slow = head, *fast = head;
		stack<ListNode*>s;
		while (fast&&fast->next)
		{
			s.push(slow);
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast)
			slow = slow->next;
		while (!s.empty())
		{
			if (s.top()->val != slow->val)
				return false;
			s.pop();
			slow = slow->next;
		}
		return true;;
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
//�ݹ�
class Solution {
	ListNode*fptr;
public:
	bool recursioncheck(ListNode*cur)
	{
		if (cur)
		{
			if (!recursioncheck(cur->next))//�ݹ�ֱ�ӴӺ���ǰ����
				return false;
			if (fptr->val != cur->val)
				return false;
			fptr = fptr->next;
		}
		return true;
	}
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		fptr = head;
		return recursioncheck(head);
	}
};
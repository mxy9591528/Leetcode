//单链表
class MyLinkedList {
	int size;
	ListNode*head;
public:
	MyLinkedList() {
		this->size = 0;
		this->head = new ListNode(0);
	}

	int get(int index) {
		if (index < 0 || index >= size)
			return -1;
		ListNode*cur = head->next;
		while (index--)
			cur = cur->next;
		return cur->val;
	}

	void addAtHead(int val) {
		addAtIndex(0, val);
	}

	void addAtTail(int val) {
		addAtIndex(size, val);
	}

	void addAtIndex(int index, int val) {
		if (index > size)
			return;
		index = max(0, index);
		ListNode*pre = head;
		while (index--)
			pre = pre->next;
		ListNode*node = new ListNode(val);
		node->next = pre->next;
		pre->next = node;
		this->size++;
	}

	void deleteAtIndex(int index) {
		if (index < 0 || index >= size)
			return;
		ListNode*pre = head;
		while (index--)
			pre = pre->next;
		ListNode*tmp = pre->next;
		pre->next = pre->next->next;
		delete tmp;
		this->size--;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


//双向链表
struct DLinkListNode {
	int val;
	DLinkListNode *prev, *next;
	DLinkListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};
class MyLinkedList {
public:
	MyLinkedList() {
		this->size = 0;
		this->head = new DLinkListNode(0);
		this->tail = new DLinkListNode(0);
		head->next = tail;
		tail->prev = head;
	}

	int get(int index) {
		if (index < 0 || index >= size)
			return -1;
		DLinkListNode *cur;
		if (index + 1 < size - index) {
			cur = head;
			for (int i = 0; i <= index; i++)
				cur = cur->next;
		}
		else {
			cur = tail;
			for (int i = 0; i < size - index; i++)
				cur = cur->prev;
		}
		return cur->val;
	}

	void addAtHead(int val) {
		addAtIndex(0, val);
	}

	void addAtTail(int val) {
		addAtIndex(size, val);
	}

	void addAtIndex(int index, int val) {
		if (index > size)
			return;
		index = max(0, index);
		DLinkListNode *pre, *cur;
		if (index < size - index)
		{
			pre = head;
			for (int i = 0; i < index; i++)
				pre = pre->next;
			cur = pre->next;
		}
		else
		{
			cur = tail;
			for (int i = 0; i < size - index; i++)
				cur = cur->prev;
			pre = cur->prev;
		}
		size++;
		DLinkListNode *node = new DLinkListNode(val);
		node->prev = pre;
		node->next = cur;
		pre->next = node;
		cur->prev = node;
	}

	void deleteAtIndex(int index)
	{
		if (index < 0 || index >= size)
			return;
		DLinkListNode *pre, *cur;
		if (index < size - index)
		{
			pre = head;
			for (int i = 0; i < index; i++)
				pre = pre->next;
			cur = pre->next->next;
		}
		else
		{
			cur = tail;
			for (int i = 0; i < size - index - 1; i++)
				cur = cur->prev;
			pre = cur->prev->prev;
		}
		size--;
		DLinkListNode *p = pre->next;
		pre->next = cur;
		cur->prev = pre;
		delete p;
	}
private:
	int size;
	DLinkListNode *head;
	DLinkListNode *tail;
};

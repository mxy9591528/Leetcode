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
        ListNode*dummy=new ListNode(0,head),*fast=head,*slow=dummy;
        while(n--)
            fast=fast->next;
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode*tmp=slow->next;
        slow->next=slow->next->next;
        delete tmp;
        return dummy->next;
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
        ListNode*dummy=new ListNode(0,head),*cur=dummy;
        while(cur)
        {
            s.push(cur);
            cur=cur->next;
        }
        while(n--)
            s.pop();
        ListNode*tmp=s.top()->next;
        s.top()->next=s.top()->next->next;
        delete tmp;
        return dummy->next;
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
class Solution {
public:
    int getsize(ListNode*p)
    {
        int len=0;
        while(p)
        {
            p=p->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(0,head),*cur=dummy;
        int len=getsize(head);
        for(int i=0;i<len-n;i++)
            cur=cur->next;
        ListNode*tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        return dummy->next;
    }
};

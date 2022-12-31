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
//辅助数组
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        ListNode*cur=head;
        while(cur)
        {
            v.emplace_back(cur->val);
            cur=cur->next;
        }
        for(int i=0;i<v.size()/2;i++)
            if(v[i]!=v[v.size()-i-1])
                return false;
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
//递归
class Solution {
    ListNode*frontpoint;
public:
    bool check(ListNode*p)
    {
        if(p)
        {
            if(!check(p->next))
                return false;
            if(p->val!=frontpoint->val)
                return false;
            frontpoint=frontpoint->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontpoint=head;
        return check(head);
    }
};

//双指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head),*secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head,*p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr,*cur = head;
        while (cur) {
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head,*slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

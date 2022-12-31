/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//哈希表
class Solution {
public:
    unordered_map<ListNode*,int>m;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA)
        {
            m[headA]++;
            headA=headA->next;
        }
        while(headB)
        {
            if(m.count(headB))
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};
//双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA  ? headB : pA->next;
            pB = pB  ? headA : pB->next;
        }
        return pA;
    }
};

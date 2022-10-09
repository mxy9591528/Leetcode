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
//环形法
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (!k||!head ||!head->next )
            return head;
        int n = 1;
        ListNode*cur = head;
        while (cur->next)
        {
            cur=cur->next;
            n++;
        }
        int num = n - k % n;
        if (num == n)
            return head;
        //放在后面先进行边界判断
        cur->next=head;
        while (num--)
            cur=cur->next;
        ListNode*tmp=cur->next;
        cur->next = nullptr;
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
//辅助数组
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head)
            return nullptr;
        vector<ListNode*>v;
        ListNode*cur = head;
        while (cur )
        {
            v.emplace_back(cur);
            cur = cur->next;
        }
        int size = v.size();
        int number = size-k % size;
        if (!number||number==size)
            return head;
        ListNode*lastNode = v[number-1];
        lastNode->next=nullptr;
        ListNode*node =v[number];
        cur = node;
        for (int i = 1; i < k%size; i++)
            node = node->next;
        node->next = head;
        return cur;
    }
};

//双指针
class Solution {
public:
    ListNode*rotateRight(ListNode*head, int k) {
        if (!head || !k) return head;
        // 计算有效的 k 值：对于与链表长度成整数倍的「旋转」都是没有意义的（旋转前后链表不变）
        int tot = 0;
        ListNode*tmp = head;
        while (tmp  && ++tot > 0) tmp = tmp->next;
        k %= tot;
        if (!k) return head;

        // 使用「快慢指针」找到倒数第 k 个节点（新头结点）：slow 会停在「新头结点」的「前一位」，也就是「新尾结点」
        ListNode*slow = head, *fast = head;
        while (k-- > 0) fast = fast->next;
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // 保存新头结点，并将新尾结点的 next 指针置空
        ListNode*nHead = slow->next;
        slow->next = nullptr;
        // 将新链表的前半部分（原链表的后半部分）与原链表的头结点链接上
        fast->next = head;
        return nHead;
    }
};

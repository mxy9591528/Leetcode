/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//哈希递归
class Solution {
public:
    unordered_map<Node*,Node*>m;
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        if(!m.count(head))
        {
            Node*newHead=new Node(head->val);
            m[head]=newHead;
            newHead->next=copyRandomList(head->next);
            newHead->random=copyRandomList(head->random);
        }
        return m[head];
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//哈希非递归
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        unordered_map<Node*,Node*>m;
        Node*cur=head;
        while(cur)
        {
            m[cur]=new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur)
        {
            //节点已被记录新建，只需连接
            m[cur]->next=m[cur->next];
            m[cur]->random=m[cur->random];
            cur=cur->next;
        }
        return m[head];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//分步迭代
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        for(Node*cur=head;cur;cur=cur->next->next)
        {
            Node*node=new Node(cur->val);
            node->next=cur->next;
            cur->next=node;
        }
        for(Node*cur=head;cur;cur=cur->next->next)
        {
            Node*node=cur->next;
            node->random=(cur->random)?cur->random->next:NULL;
        }
        Node*newHead=head->next;
        for(Node*cur=head;cur;cur=cur->next)
        {
            Node*tmp=cur->next;
            cur->next=cur->next->next;
            tmp->next=(tmp->next)?tmp->next->next:NULL;
        }
        return newHead;
    }
};

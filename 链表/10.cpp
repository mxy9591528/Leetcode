/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
//辅助栈
class Solution {
public:
    Node* flatten(Node* head) {
        Node*cur=head,*pre=nullptr;
        stack<Node*>s;
        while(cur||!s.empty())
        {
            if(!cur)
            {
                cur=s.top();
                s.pop();
                cur->prev=pre;
                pre->next=cur;
            }
            if(cur->child)
            {
                if(cur->next)
                    s.push(cur->next);
                cur->child->prev=cur;
                cur->next=cur->child;
                cur->child=nullptr;
            }
            pre=cur;
            cur=cur->next;
        }
        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
//简化
class Solution {
public:
    Node* flatten(Node* head) {
        Node*p=nullptr;
        stack<Node*>s;
        if(head)
            s.push(head);
        while(s.size())
        {
            auto cur=s.top();
            s.pop();
            if(p)
                p->next=cur;
            cur->prev=p;
            p=cur;
            if(cur->next)
                s.push(cur->next);
            if(cur->child)
            {
                s.push(cur->child);
                cur->child=nullptr;
            }
        }
        return head;
    }
};

//dfs
class Solution {
public:
    Node* flatten(Node* head) {
        function<Node*(Node*)> dfs = [&](Node* node) {
            Node* cur = node,*last = nullptr;
            while (cur) {
                Node* next = cur->next;
                //  如果有子节点，那么首先处理子节点
                if (cur->child)
                {
                    Node* child_last = dfs(cur->child);
                    next = cur->next;
                    //  将 node 与 child 相连
                    cur->next = cur->child;
                    cur->child->prev = cur;
                    //  如果 next 不为空，就将 last 与 next 相连
                    if (next)
                    {
                        child_last->next = next;
                        next->prev = child_last;
                    }
                    // 将 child 置为空
                    cur->child = nullptr;
                    last = child_last;
                }
                else
                    last = cur;
                cur = next;
            }
            return last;
        };
        dfs(head);
        return head;
    }
};

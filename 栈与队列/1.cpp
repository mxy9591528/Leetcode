//数组
class MyCircularQueue {
    vector<int>v;
    int head,tail,size;
public:
    MyCircularQueue(int k) {
        v.resize(k);
        head=tail=-1;
        size=k;
    }

    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty())
            head=0;
        tail=(tail+1)%size;
        v[tail]=value;
        return true;
    }

    bool deQueue() {
        if(isEmpty())
            return false;
        if(head==tail)
        {
            head=tail=-1;
            return true;
        }
        head=(head+1)%size;
        return true;
    }

    int Front() {
        if(isEmpty())
            return -1;
        return v[head];
    }

    int Rear() {
        if(isEmpty())
            return -1;
        return v[tail];
    }

    bool isEmpty() {
        return head==-1;
    }

    bool isFull() {
        return (tail+1)%size==head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

//链表
class MyCircularQueue {
    ListNode*head,*tail;
    int size,capacity;
public:
    MyCircularQueue(int k) {
        head=tail=nullptr;
        capacity=k;
        size=0;
    }

    bool enQueue(int value) {
        if(isFull())
            return false;
        ListNode*node=new ListNode(value);
        if(!head)
            head=tail=node;
        else
        {
            tail->next=node;
            tail=node;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if(isEmpty())
            return false;
        ListNode*tmp=head;
        head=head->next;
        delete tmp;
        size--;
        return true;
    }

    int Front() {
        if(isEmpty())
            return -1;
        return head->val;
    }

    int Rear() {
        if(isEmpty())
            return -1;
        return tail->val;
    }

    bool isEmpty() {
        return size==0;
    }

    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

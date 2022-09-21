class MinStack {
    stack<int> s,mins;
public:
    MinStack() {
        mins.push(INT32_MAX);
    }

    void push(int x) {
        s.push(x);
        mins.push(min(mins.top(), x));
    }

    void pop() {
        s.pop();
        mins.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }
};

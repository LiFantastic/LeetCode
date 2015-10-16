/*============================================================
Problem: Min Stack
==============================================================
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
============================================================*/
class MinStack {
private:
    stack<int> element;
    stack<int> minValue;
public:
    void push(int x) {
        element.push(x);
        if (minValue.empty() || x <= getMin())  minValue.push(x);       
    }
    void pop() {
        if (element.top() == getMin())  minValue.pop();
        element.pop();
    }
    int top() {
        return element.top();
    }
    int getMin() {
        return minValue.top();
    }
};
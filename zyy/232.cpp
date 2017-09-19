class MyQueue {
public:
    stack<int> elements, reverse;
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!elements.empty()) {
            reverse.push(elements.top());
            elements.pop();
        }

        elements.push(x);

        while (!reverse.empty()) {
            elements.push(reverse.top());
            reverse.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result(elements.top());
        elements.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return elements.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return elements.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

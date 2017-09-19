class MyStack {
  public:
    /** Initialize your data structure here. */
    queue<int> elements, buffer;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!elements.empty()) {
            buffer.push(elements.front());
            elements.pop();
        }

        elements.push(x);

        while (!buffer.empty()) {
            elements.push(buffer.front());
            buffer.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret(elements.front());
        elements.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return elements.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return elements.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

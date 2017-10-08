class MyQueue {
private:
    stack<int> pushStack;
    stack<int> popStack;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        pushStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        popStack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        return popStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStack.empty() && popStack.empty();
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

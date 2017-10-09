class MyStack {
private:
    queue<int> vals;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        vals.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        int endVal = vals.front();
        vals.pop();
        while (!vals.empty()) {
            tmp.push(endVal);
            endVal = vals.front();
            vals.pop();
        }
        vals = tmp;
        return endVal;
    }
    
    /** Get the top element. */
    int top() {
        int endVal = pop();
        vals.push(endVal);
        return endVal;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return vals.empty();
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

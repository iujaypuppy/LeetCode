class MinStack {
private:
    stack<int> valStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        valStack.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        } else if (minStack.top() < x) {
            minStack.push(minStack.top());
        } else {
            minStack.push(x);
        }
    }
    
    void pop() {
        valStack.pop();
        minStack.pop();
    }
    
    int top() {
        return valStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

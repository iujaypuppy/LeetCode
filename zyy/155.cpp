class MinStack {
  public:
    /** initialize your data structure here. */
    class Element {
      public:
        int x;
        int min;
        Element(int element, int minDownwards): x(element), min(minDownwards) {}
    };
    stack<Element> s;
    MinStack() {
    }
    
    void push(int x) {
        s.push(Element(x, s.empty() ? x : min(x, getMin())));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().x;
    }
    
    int getMin() {
        return s.top().min;
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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  private:
    class IterPair {
      public:
        vector<NestedInteger>::const_iterator begin, end;
        IterPair(const vector<NestedInteger> &vec):
                begin(vec.begin()), end(vec.end()) {}
    };
    stack<IterPair> state;
    bool pushUntilInteger(const vector<NestedInteger> &n) {
        if (n.empty()) {
            return false;
        }

        state.push(IterPair(n));
        vector<NestedInteger>::const_iterator &i(state.top().begin);
        while (i != n.end() && !i->isInteger() && !pushUntilInteger(i->getList())) {
            i++;
        }
        if (i == n.end()) {
            state.pop();
            return false;
        }
        return true;
    }

    void removeEmptyStackEntry(void) {
        while (!state.empty() && state.top().begin == state.top().end) {
            state.pop();
            if (!state.empty()) {
                state.top().begin++;
            }
        }
    }
    void pushTop(void) {
        while (!state.empty() && state.top().begin != state.top().end &&
               !state.top().begin->isInteger()) {
            if (!pushUntilInteger(state.top().begin->getList())) {
                state.top().begin++;
                removeEmptyStackEntry();
                continue;
            }
        }
    }

  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        pushUntilInteger(nestedList);
    }

    int next() {
        int ret(state.top().begin->getInteger());
        state.top().begin++;
        removeEmptyStackEntry();
        pushTop();

        return ret;
    }

    bool hasNext() {
        return !state.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

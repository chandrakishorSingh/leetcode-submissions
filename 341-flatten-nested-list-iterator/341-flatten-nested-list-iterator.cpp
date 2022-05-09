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
public:
    stack<NestedInteger> st;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++) {
            _push((*it), st);
        }
    }
    
    int next() {
        int result = st.top().getInteger();
        st.pop();
        return result;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
private:
    void _push(NestedInteger& item, stack<NestedInteger>& st) {
        if (item.isInteger())
            st.push(item.getInteger());
        else {
            auto list = item.getList();
            for (auto it = list.rbegin(); it != list.rend(); it++)
                _push(*it, st);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// TC: O(n)
// SC: O(max(# of level of nestedness))
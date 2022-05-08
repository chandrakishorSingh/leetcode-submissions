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
    vector<int> arr;
    int currentIndex = -1;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto list: nestedList) {
            if (list.isInteger()) {
                arr.push_back(list.getInteger());
            } else {
                dfs(list);
            }
        }
    }
    
    int next() {
        return arr[++currentIndex];
    }
    
    bool hasNext() {
        return currentIndex + 1 != arr.size();
    }
    
private:
    void dfs(NestedInteger& list) {
        if (list.isInteger()) {
            arr.push_back(list.getInteger());
        } else {
            for (auto nestedList: list.getList())
                dfs(nestedList);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
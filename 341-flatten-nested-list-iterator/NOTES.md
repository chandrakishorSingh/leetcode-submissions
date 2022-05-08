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
​
/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/
​
// TC: O(n)
// SC: O(max(# of level of nestedness))
```
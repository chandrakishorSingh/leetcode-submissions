public:
queue<int> que;
void push(int x) {
int n = que.size();
que.push(x);
for (int i = 0; i < n; i++) {
que.push(que.front());
que.pop();
}
}
int pop() {
int item = que.front();
que.pop();
return item;
}
int top() {
return que.front();
}
bool empty() {
return que.empty();
}
};
​
// TC: O(n^2)
// SC: O(n)
```
​
Solution 2:
​
Using one queue, making pop operation expensive O(n^2).
​
```
class MyStack {
public:
queue<int> que;
void push(int x) {
que.push(x);
}
int pop() {
int n = que.size() - 1;
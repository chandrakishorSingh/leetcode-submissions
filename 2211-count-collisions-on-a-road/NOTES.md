Solution 1:
​
**Observations:**
- If a 'S' is seen it will collide with all of the previous 'R's for which there is no 'L' or 'S' in it's right
- If a 'R' is seen then we have to wait till we see what is next
- If a 'L' is seen then
- If the left adjacent item is 'S' then it will collide with it
- If the left adjacent item is 'R' then it will collide with it. Also, if there are some series of 'R's just before this first left 'R' then they will also collide with the stationary car.
​
Since, we need to know the previous cars type in most recent order when we encounter the current car, using a stack make sense here.
​
```
class Solution {
public:
int countCollisions(string directions) {
int count = 0;
stack<char> st;
for (auto dir: directions) {
if (st.empty() && (dir == 'S' || dir == 'R')) {
st.push(dir);
continue;
}
if (dir == 'S' && st.top() != 'S') {
while (!st.empty() && st.top() == 'R') {
count++;
st.pop();
}
st.push('S');
continue;
}
if (dir == 'L' && !st.empty()) {
if (st.top() == 'S') {
count++;
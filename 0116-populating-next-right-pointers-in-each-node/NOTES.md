Solution 1:
​
​
​
Solution 2:
​
- Recursive approach.
- Observations
- For a node, the `next` pointer of its left child will always be the right child of this node.
- And for the right child of this node, the required pointer will point to the left child of the node pointed by the `next` of this node. Note that in the case of right child, the `next` of its parent will be `NULL` when this node is the right most node in the current level. In such case the `next` of its right child will also be `NULL`.
​
```
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;
​
Node() : val(0), left(NULL), right(NULL), next(NULL) {}
​
Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
​
Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/
​
class Solution {
public:
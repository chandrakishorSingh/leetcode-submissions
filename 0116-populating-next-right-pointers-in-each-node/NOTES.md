queue<Node*> que({root});
while (!que.empty()) {
Node* next = NULL;
int n = que.size();
for (int i = 0; i < n; i++) {
auto node = que.front();
que.pop();
if (node == NULL) {
continue;
}
node->next = next;
next = node;
que.push(node->right);
que.push(node->left);
}
}
return root;
}
};
​
// TC: O(n)
// SC: O(n)
```
​
Solution 2:
​
- Recursive approach.
- Observations
- For a node, the `next` pointer of its left child will always be the right child of this node.
- And for the right child of this node, the required pointer will point to the left child of the node pointed by the `next` of this node. Note that in the case of right child, the `next` of its parent will be `NULL` when this node is the right most node in the current level. In such case the `next` of its right child will also be `NULL`.
​
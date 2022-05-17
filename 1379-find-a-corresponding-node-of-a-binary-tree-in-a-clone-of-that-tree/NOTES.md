queue<pair<TreeNode*, TreeNode*>> que;
que.push({ original, cloned });
TreeNode* result = nullptr;
while (result == nullptr) {
int n = que.size();
for (int i = 0; i < n; i++) {
auto front = que.front();   que.pop();
​
if (front.first->val == target->val) {
result = front.second;
break;
}
​
if (front.first->left)
que.push({ front.first->left, front.second->left });
​
if (front.first->right)
que.push({ front.first->right, front.second->right });
}
}
return result;
}
};
​
// TC: O(n)
// SC: O(n/2)
```
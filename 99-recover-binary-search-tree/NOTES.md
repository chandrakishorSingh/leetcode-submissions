if (prev->val > root->val) {
if (first == nullptr) {
first = prev;
second = root;
} else {
second = root;
}
}
}
prev = root;
inorder(root->right, prev, first, second);
}
void recoverTree(TreeNode* root) {
TreeNode* prev = nullptr;
TreeNode* first = nullptr;
TreeNode* second = nullptr;
inorder(root, prev, first, second);
swap(first->val, second->val);
}
};
​
// TC: O(n)
// SC: O(n)
```
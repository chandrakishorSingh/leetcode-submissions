Follow up question:
​
- Yes it is possible to solve the problem even when duplicates are allowed. In this case, we can just compare the addresses of the current node of original tree and that of target node instead of comparing their values.
​
Solution 1:
​
- Simple DFS.
​
```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
​
class Solution {
public:
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
if (original == nullptr)
return nullptr;
if (target->val == cloned->val)
return cloned;
auto leftResult = getTargetCopy(original->left, cloned->left, target);
if (leftResult != nullptr)
return leftResult;
return getTargetCopy(original->right, cloned->right, target);
}
};
​
// TC: O(n)
// SC: O(height of tree)
```
​
Solution 2:
​
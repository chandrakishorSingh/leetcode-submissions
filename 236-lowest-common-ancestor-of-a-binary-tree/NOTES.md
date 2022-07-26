result.push_back(root);
return;
}
dfs(root->right, child, result, isChildSeen);
if (isChildSeen)
result.push_back(root);
}
};
​
// TC: O(n)
// SC: O(n)
```
​
Solution 3:
​
- Observe that once you found any of the two node, the least common ancestor will lie on the path of this node.
- The first node in the path of the seen node(the node which is found out first) will be the answer.
- Note that unlike 2nd solution, this is a single pass solution.
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
class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
TreeNode* result = nullptr;
bool isFirstSeen = false;
bool isSecondSeen = false;
dfs(root, p, q, result, isFirstSeen, isSecondSeen);
return result;
}
void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result, bool& isFirstSeen, bool& isSecondSeen) {
if (root == nullptr)
return;
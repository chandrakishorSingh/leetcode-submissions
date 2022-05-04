*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
bool findTarget(TreeNode* root, int k) {
unordered_set<int> mp;
bool result = false;
inorder(root, mp, k, result);
return result;
}
void inorder(TreeNode* root, unordered_set<int>& mp, int k, bool& result) {
if (root == nullptr)
return;
if (mp.count(k - root->val)) {
result = true;
return;
} else {
mp.insert(root->val);
}
inorder(root->left, mp, k, result);
if (!result)
inorder(root->right, mp, k, result);
}
};
​
// TC: O(n)
// SC: O(n)
```
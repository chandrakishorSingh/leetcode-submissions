return result;
}
};
​
// TC: O(n)
// SC: O(n)
```
​
Solution 3:
​
- This is a very concise and clever implementation.
- The idea is simple. For a given preorder subarray we will assign a upper bound on the value of any node. Then we will use recursion to do the same and further decreasing the size of the subarray.
- We need to use a global variable which will correctly point to the root of the current subtree by counting the number recursion calls made.
​
```
/**
* Definition for a binary tree node.
* struct TreeNode {
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
TreeNode* bstFromPreorder(vector<int>& preorder) {
int i = 0;
return bstFromPreorder(preorder, i, INT_MAX);
}
TreeNode* bstFromPreorder(vector<int>& preorder, int& index, int bound) {
if (index == preorder.size() || preorder[index] > bound)
return nullptr;
auto root = new TreeNode(preorder[index++]);
root->left = bstFromPreorder(preorder, index, root->val);
root->right = bstFromPreorder(preorder, index, bound);
return root;
}
};
​
// TC: O(n)
// SC: O(n)
```
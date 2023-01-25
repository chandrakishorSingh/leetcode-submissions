*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
TreeNode* sortedListToBST(ListNode* head) {
vector<int> nums;
ListNode* current = head;
while (current != nullptr) {
nums.push_back(current->val);
current = current->next;
}
return dfs(nums, 0, nums.size() - 1);
}
TreeNode* dfs(vector<int>& nums, int left, int right) {
if (left > right)
return nullptr;
int mid = left + (right - left) / 2;
auto node = new TreeNode(nums[mid]);
node->left = dfs(nums, left, mid - 1);
node->right = dfs(nums, mid + 1, right);
return node;
}
};
​
// TC: O(n)
// SC: O(log(n))
```
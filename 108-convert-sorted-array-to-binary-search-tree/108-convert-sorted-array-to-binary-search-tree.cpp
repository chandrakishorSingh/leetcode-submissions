/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        
        int mid = left + ((right - left) / 2);
        
        auto node = new TreeNode(nums[mid]);
        node->left = _sortedArrayToBST(nums, left, mid - 1);
        node->right = _sortedArrayToBST(nums, mid + 1, right);
        
        return node;
    }
};
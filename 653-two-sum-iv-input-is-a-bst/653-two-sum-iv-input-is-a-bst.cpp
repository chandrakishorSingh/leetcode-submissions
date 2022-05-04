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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        
        int start = 0;
        int end = arr.size() - 1;
        bool result = false;
        while (start < end) {
            int sum = arr[start] + arr[end];
            
            if (sum > k)
                end--;
            else if (sum < k)
                start++;
            else {
                result = true;
                break;
            }
        }
        
        return result;
    }
    
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};
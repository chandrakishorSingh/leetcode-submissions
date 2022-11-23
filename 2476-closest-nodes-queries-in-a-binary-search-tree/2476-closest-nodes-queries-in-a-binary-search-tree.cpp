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
    int ceil(vector<int>& values, int val) {
        int low = 0;
        int high = values.size() - 1;
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (values[mid] == val)
                return val;
            
            if (values[mid] > val) {
                result = values[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
    
    int floor(vector<int>& values, int val) {
        int low = 0;
        int high = values.size() - 1;
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (values[mid] == val)
                return val;
            
            if (values[mid] < val) {
                result = values[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
    
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;
        
        inorder(root->left, nums);
        nums.push_back(root->val);        
        inorder(root->right, nums);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> values;
        inorder(root, values);
        
        vector<vector<int>> result(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            result[i] = { floor(values, query), ceil(values, query) };
        }
        
        return result;
    }
};
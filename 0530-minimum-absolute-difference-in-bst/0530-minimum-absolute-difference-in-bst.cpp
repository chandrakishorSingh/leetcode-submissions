class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        TreeNode* prev = nullptr;
        _getMinimumDifference(root, prev, minimum);
        
        return minimum;
    }
    
    void _getMinimumDifference(TreeNode* current, TreeNode*& prev, int& minimum) {
        if (current == nullptr)
            return;
        
        _getMinimumDifference(current->left, prev, minimum);
        
        if (prev != nullptr)
            minimum = min(minimum, abs(current->val - prev->val));
        
        prev = current;
        
        _getMinimumDifference(current->right, prev, minimum);
    }
};
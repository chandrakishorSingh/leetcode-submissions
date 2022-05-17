/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr)
            return nullptr;
        
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({ original, cloned });
        
        TreeNode* result = nullptr;
        while (result == nullptr) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                auto front = que.front();   que.pop();

                if (front.first->val == target->val) {
                    result = front.second;
                    break;
                }

                if (front.first->left)
                    que.push({ front.first->left, front.second->left });

                if (front.first->right)
                    que.push({ front.first->right, front.second->right });
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(height of tree)
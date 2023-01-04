/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        
        dfs(root->left, root, true);
        dfs(root->right, root, false);
        
        return root;
    }
    
    void dfs(Node* node, Node* parent, bool isLeftChild) {
        if (node == NULL)
            return;
        
        node->next = isLeftChild ? parent->right : (parent->next == NULL ? NULL : parent->next->left);
        
        dfs(node->left, node, true);
        dfs(node->right, node, false);
    }
};

// TC: O(n)
// SC: O(n)
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
        _connect(root);
        
        return root;
    }
    
    void _connect(Node* node) {
        if (node == NULL)
            return;
        
        if (node->left) {
            node->left->next = node->right;
        }
        
        if (node->right) {
            node->right->next = node->next ? node->next->left : NULL;
        }
        
        _connect(node->left);
        _connect(node->right);
    }
};

// TC: O(n)
// SC: O(n)
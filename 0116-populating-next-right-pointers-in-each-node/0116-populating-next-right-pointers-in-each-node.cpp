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
        dfs(root->right, root->next, false);
        
        return root;
    }
    
    void dfs(Node* node, Node* aux, bool isLeftChild) {
        if (node == NULL)
            return;
        
        node->next = isLeftChild ? aux->right : (aux == NULL ? NULL : aux->left);
        
        dfs(node->left, node, true);
        dfs(node->right, node->next, false);
    }
};
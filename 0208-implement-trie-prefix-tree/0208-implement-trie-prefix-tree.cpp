class Trie {
public:
    
    class Node {
        public:
            bool isEnd;
            vector<Node*> children;
            
        
        Node() {
            this->children.resize(26, nullptr);
            this->isEnd = false;
        }
    };
    
    Node* root;
    
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        Node* current = root;
        
        for (auto ch : word) {
            int pos = ch - 'a';
            
            if (current->children[pos] == nullptr) {
                current->children[pos] = new Node();
            }
            
            current = current->children[pos];
        }
        
        current->isEnd = true;
    }
    
    bool search(string word) {
        Node* current = root;
        
        for (auto ch : word) {
            int pos = ch - 'a';
            
            if (current->children[pos] == nullptr) {
                return false;
            }
            
            current = current->children[pos];
        }
        
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        
        for (auto ch : prefix) {
            int pos = ch - 'a';
            
            if (current->children[pos] == nullptr) {
                return false;
            }
            
            current = current->children[pos];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
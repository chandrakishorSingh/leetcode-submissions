class LRUCache {
private:
    class DoublyLinkedListNode {
        public:
            int key;
            int value;
            DoublyLinkedListNode* left;
            DoublyLinkedListNode* right;
        
            DoublyLinkedListNode(int key, int value, DoublyLinkedListNode* left=nullptr, DoublyLinkedListNode* right=nullptr) {
                this->key = key;
                this->value = value;
                this->left = left;
                this->right = right;
            }
    };
    
    class DoublyLinkedList {
        // private:
        public:
            DoublyLinkedListNode* head;
            DoublyLinkedListNode* tail;
            int currentSize;
        
        public:
            DoublyLinkedList() {
                this->head = nullptr;
                this->tail = nullptr;
                this->currentSize = 0;
            }
        
            DoublyLinkedListNode* push_front(int key, int value) {
                DoublyLinkedListNode* node = new DoublyLinkedListNode(key, value);
                
                if (this->head == nullptr) {
                    this->tail = node;
                } else {
                    node->right = this->head;
                    this->head->left = node;
                }

                this->head = node;
                
                this->currentSize++;
                
                return node;
            }
        
            void push_front(DoublyLinkedListNode* node) {
                if (this->head == nullptr) {
                    this->tail = node;
                } else {
                    node->right = this->head;
                    this->head->left = node;
                }
                
                this->head = node;
            }
        
            int pop_back() {
                int key = this->tail->key;
                
                auto nodeRef = this->tail;
                this->tail = this->tail->left;
                // delete(nodeRef);
                
                this->currentSize--;
                
                return key;
            }
        
            void remove(DoublyLinkedListNode* node) {
                if (node->right != nullptr)
                    node->right->left = node->left;
                
                if (node->left != nullptr)
                    node->left->right = node->right;
                
                if (node == this->head)
                    this->head = this->head->right;
                
                if (node == this->tail)
                    this->tail = this->tail->left;
                
                node->left = nullptr;
                node->right = nullptr;
            }
        
            int size() {
                return this->currentSize;
            }
    };

private:
    DoublyLinkedList lst;
    map<int, DoublyLinkedListNode*> keyToNodeMap;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (keyToNodeMap.count(key)) {
            auto node = keyToNodeMap[key];
            lst.remove(node);
            lst.push_front(node);
            
            return keyToNodeMap[key]->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (keyToNodeMap.count(key)) {
            auto node = keyToNodeMap[key];
            node->value = value;
            
            lst.remove(node);
            lst.push_front(node);
        } else {
            keyToNodeMap[key] = lst.push_front(key, value);
        }
        
        if (lst.size() > this->capacity) {
            auto key = lst.pop_back();
            keyToNodeMap.erase(key);
            // cout << "deleted key is " << key << endl;
        }
        
        // cout << "tail is " << lst.tail->key << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
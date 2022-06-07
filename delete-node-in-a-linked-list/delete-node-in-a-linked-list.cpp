class Solution {
public:
    void deleteNode(ListNode* node) {
        auto ref = node->next;

        node->val = node->next->val;
        node->next = node->next->next;

        delete(ref);
    }
};

// TC: O(1)
// SC: O(1)
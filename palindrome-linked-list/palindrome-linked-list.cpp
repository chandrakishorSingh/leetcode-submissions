/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* it = head;
        
        bool result = true;
        _isPalindrome(head, it, result);
        
        return result;
    }
    
    void _isPalindrome(ListNode* node, ListNode*& it, bool& result) {
        if (node == nullptr)
            return;
        
        _isPalindrome(node->next, it, result);
        
        if (it->val != node->val) {
            result = false;
        }
        
        it = it->next;
    }
};
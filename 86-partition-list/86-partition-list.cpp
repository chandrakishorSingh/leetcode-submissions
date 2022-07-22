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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;
        ListNode* end1 = nullptr;
        ListNode* end2 = nullptr;
        
        ListNode* current = head;
        while (current != nullptr) {
            if (current->val < x) {
                if (head1 == nullptr) {
                    head1 = current;
                    end1 = head1;
                } else {
                    end1->next = current;
                    end1 = end1->next;
                }
            } else {
                if (head2 == nullptr) {
                    head2 = current;
                    end2 = head2;
                } else {
                    end2->next = current;
                    end2 = end2->next;
                }
            }
            
            current = current->next;
        }
        
        if (end1 != nullptr)
            end1->next = head2;
        
        if (end2 != nullptr)
            end2->next = nullptr;
        
        return head1 == nullptr ? head2 : head1;
    }
};

// TC: O(n)
// SC: O(1)
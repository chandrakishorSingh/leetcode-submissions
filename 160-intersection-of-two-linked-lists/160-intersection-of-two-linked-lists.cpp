/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        
        while (iter1 != iter2) {
            iter1 = iter1 == nullptr ? headB: iter1->next;
            iter2 = iter2 == nullptr ? headA: iter2->next;
        }
        
        return iter1;
    }
};

// TC: O(m + n)
// SC: O(1)
// m, n are lengths of the given linked list
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        ListNode* result = new ListNode();
        ListNode* it = result;
        
        while (it1 || it2) {
            if (!it1) {
                it->next = new ListNode(it2->val);
                it2 = it2->next;
            } else if (!it2) {
                it->next = new ListNode(it1->val);
                it1 = it1->next;
            } else if (it1->val < it2->val) {
                it->next = new ListNode(it1->val);
                it1 = it1->next;
            } else {
                it->next = new ListNode(it2->val);
                it2 = it2->next;
            }
            it = it->next;
        }
        
        return result->next;
    }
};
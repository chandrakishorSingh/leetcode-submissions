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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* nodeBeforeStart = nullptr;
        ListNode* nodeAfterEnd = nullptr;
        
        ListNode* current = head;
        for (int i = 1; i <= right; i++) {
            if (i > 1 && i <= left)
                nodeBeforeStart = start;
            
            if (i <= left)
                start = current;
            
            end = current;
            nodeAfterEnd = current->next;
            
            current = current->next;
        }
        
        // cout << nodeBeforeStart->val << endl;
        
        if (nodeBeforeStart != nullptr)
            nodeBeforeStart->next = reverse(start, right - left + 1);
        else
            reverse(start, right - left + 1);
        
        
        if (nodeAfterEnd != nullptr)
            start->next = nodeAfterEnd;
        
        return nodeBeforeStart != nullptr ? head : end;
    }
    
    ListNode* reverse(ListNode* start, int length) {
        if (length == 1)
            return start;
        
        ListNode* current = start;
        ListNode* prev = nullptr;
        
        for (int i = 1; i <= length; i++) {
            auto next = current->next;
            
            current->next = prev;
            
            prev = current;
            current = next;
        }
        
//         auto it = prev;
//         for (int i = 1; i <= length; i++) {
//             cout << it->val << " ";
//             it = it->next;
//         }
        
//         cout << endl;
        
        return prev;
    }
};
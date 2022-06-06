Solution 1:
​
- The intersection node is the first node which is common in both of the linked list.
- Hence, we can store all of the links(addresses) of one linked list. Then we can traverse the other linked list and see if the current link is already seen or not.
- Since lookup time is important here, we use a `unordered_set`.
​
```
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
unordered_set<ListNode*> links;
while (headA != nullptr) {
links.insert(headA);
headA = headA->next;
}
while (headB != nullptr) {
if (links.count(headB))
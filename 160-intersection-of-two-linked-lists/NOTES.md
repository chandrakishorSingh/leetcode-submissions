​
Solution 2:
​
- If the given two linked-list intersect then we have following two cases.
- If the length of both lists are same then we can just advance the pointers until both points to the same node.
- Otherwise, we need to advance the pointer, with longer length, until its distance with the tail becomes the same as the smaller one. Then it will be the same case as above one.
- If the lists don't intersect then we will just return `NULL`.
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
int length1 = getLength(headA);
int length2 = getLength(headB);
if (length1 > length2)
swap(headA, headB);
for (int i = 0; i < abs(length1 - length2); i++)
headB = headB->next;
while (headA != headB) {
headA = headA->next;
headB = headB->next;
}
return headA;
}
int getLength(ListNode* head) {
int result = 0;
while (head != nullptr) {
head = head->next;
result++;
}
return result;
}
};
​
// TC: O(m + n)
// SC: O(1)
// m, n are lengths of the given linked list
```
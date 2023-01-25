TODO:
​
- Optimal solution, new algorithm: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/549841/C%2B%2B-DSW
​
Solution 1:
​
- It's easy to see that in order to create a height balanced BST, we need to select the middle element and "break" the list in two halves.
- One half may have one extra element than the other when the number of elements is odd and in such case any of the two middle elements can be chosen as root.
- Since, the given list of elements is provided in linked list format, we just need to insert them into an array like structure to access them using indices.
- Note that TC, will be linear and not linearithmic. A simple analysis using recurrence relations will give the result.
​
```
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
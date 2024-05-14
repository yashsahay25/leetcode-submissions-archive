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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *p = headA, *q = headB;

        while (p != q) {
            p = (p) ? p->next : headB;
            // Move p to the next node or switch to headB if it reaches the end
            q = (q) ? q->next : headA;
            // Move q to the next node or switch to headA if it reaches the end
        }

        return p; // q
    }
};
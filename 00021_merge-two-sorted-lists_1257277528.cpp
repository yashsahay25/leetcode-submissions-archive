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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *p = list1, *q = list2;
        ListNode* dummy = new ListNode(-1); // dummy header
        ListNode* temp = dummy;               // traversal

        while (p && q) {
            if (p->val < q->val) {
                temp->next = p;
                temp = p;
                p = p->next;
            } else {
                temp->next = q;
                temp = q;
                q = q->next;
            }
        }
        if (p)
            temp->next = p;
        else
            temp->next = q;

        return dummy->next;
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head, *q=head;
        for(int i=0;i<n;i++)
            q=q->next; // move q by n places

        if (!q) return head->next; // if out of list

        while(q->next){ // traverse till last node
            p=p->next;
            q=q->next;  // move both together
        }
        p->next=p->next->next;
        return head;
    }
};
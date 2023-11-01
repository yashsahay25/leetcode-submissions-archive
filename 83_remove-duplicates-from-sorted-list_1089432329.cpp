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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while(p && p->next){
            if(p->val == p->next->val){
                ListNode *q = p->next;
                p->next = q->next; // or p->next->next
                q->next = NULL;
                delete(q);
                continue; // this helps to remove all next multiple duplicates
            }
            p=p->next;
        }
        return head;
    }
};
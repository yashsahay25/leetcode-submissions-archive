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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;

        ListNode *odd = head;
        ListNode *even = head->next;

        ListNode *evenHead = even; // store 1st even node
        while(even && even->next){
            // for odd
            odd->next = odd->next->next;
            odd=odd->next;

            // for even
            even->next = even->next->next;
            even=even->next;
        }
        // join 
        odd->next = evenHead;
        return head;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr){
            if(curr->val==val){
                // if node to be deleted is head node
                if(!prev){
                    head = curr->next;
                    // curr = curr->next;
                }
                // otherwise
                else{
                    prev->next = curr->next;
                    // curr = curr->next;
                }
            }
            else{
                prev = curr;
                // curr = curr->next; already being done below
            }
            curr = curr->next;
        }
        return head;
    }
};
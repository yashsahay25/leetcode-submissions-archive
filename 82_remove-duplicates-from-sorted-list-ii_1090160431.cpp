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
        // base case
        if (!head || !head->next)
            return head;
        // dummy node to act as head, if head is duplicate element
        ListNode* dummy = new ListNode(-101); 
        dummy->next = head; // place dummy before head

        ListNode* curr = dummy; // start traversal from dummy node

        while (curr->next && curr->next->next) 
        {
            if (curr->next->val == curr->next->next->val) 
            {
                ListNode* temp1 = curr->next->next; // to track for deletion
                
                while (temp1 != NULL && curr->next->val == temp1->val) 
                {
                    ListNode* temp2 = temp1;
                    temp1 = temp1->next;
                    delete temp2;
                }
                curr->next = temp1;
            } 
            else 
            {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
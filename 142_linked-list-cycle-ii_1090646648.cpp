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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=slow;
        while(slow && fast && fast->next){
            slow=slow->next;        // move slow by 1
            fast=fast->next->next;  // move fast by 2
            if(slow==fast){         // slow & fast meet if there's a loop
                ListNode *temp=head;    // new pointer at head
                while(temp!=slow){ 
                    temp=temp->next;    // move both slow & temp until they meet
                    slow=slow->next;
                }
                return temp;    // meeting point is first node of loop
            }
        }
        return NULL;
    }
};
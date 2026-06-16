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
    ListNode* deleteMiddle(ListNode* head) {
        // edge case - single node
        if(!head || !head->next) return nullptr;

        // 3 pointers
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        // now slow points to mid

        // connect prev to mid's next & free up slow
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
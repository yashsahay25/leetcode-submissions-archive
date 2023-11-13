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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return head;
        if(left==right) return head;

        // dummy will act as prev of head, incase head is also to be reversed
        ListNode *dummy = new ListNode(); // dummy node
        dummy->next = head; // always points to head

        ListNode *preLeft=dummy; // ptr to track prev of starting node
        ListNode *curr=head;

        for(int i=0;i<left-1;i++){
            preLeft=preLeft->next;
            curr=curr->next;
        }

        // ptr to left node, where we start reversing
        // after reversing, join this node to the last node
        ListNode *leftHead = curr;

        // reverse logic (same as whole reversal)
        ListNode *prev=NULL;
        // run loop for (right-left+1) times
        for(int i=0;i<=right-left;i++){
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // join the ends
        preLeft->next = prev;
        leftHead->next = curr;

        return dummy->next;
    }
};
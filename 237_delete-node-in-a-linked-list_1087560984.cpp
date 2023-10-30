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
    void deleteNode(ListNode* node) {
        // instead of deleting the given node, we copy next value into it
        // & delete next node
        ListNode *temp = node->next; // ptr to next node
        node->val = temp->val; // copy value of next node in this node;
        // delete next node
        node->next = temp->next;
        temp->next = NULL;
        delete(temp);
    }
};
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
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next; // move fast by n places

        if (!fast)
            return head->next; // if out of list

        while (fast->next) { // traverse until last node
            slow = slow->next;
            fast = fast->next; // move both together
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return head;
    }
};
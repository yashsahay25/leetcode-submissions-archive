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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // find middle of linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow now points to the start of the 2nd half of the list

        // reverse the 2nd half
        ListNode* prev = nullptr;
        while (slow) {
            // prev, curr=slow, nxt=slow->next
            ListNode* nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        // traverse both halfs together & calc sum
        int ans = 0;
        ListNode* p = head;
        ListNode* q = prev;
        while (q) {
            int sum = p->val + q->val;
            ans = max(ans, sum);
            p = p->next;
            q = q->next;
        }

        return ans;
    }
};
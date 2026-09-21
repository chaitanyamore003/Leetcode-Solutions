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
    ListNode* detectCycle(ListNode* head) {
        // optimal
        //Floyd's Cycle Detection II

        // using two pointers slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // cycle exists
            if (slow == fast) {
                // reset slow
                slow = head;

                // finding the enterance of the cycle
                // now both pointers move one step at a time
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // they both meet on the enterance of the cycle hence return any
                // of them
                return slow;
            }
        }
        return nullptr;
    }
};
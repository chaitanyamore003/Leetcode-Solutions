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
        // taking two pointers slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // creating a gap of n between the pointers
        for (int i = 0; i < n; i++) {
            if (fast == nullptr)
                return head; // n is greater than list length

            fast = fast->next;
        }

        if (fast == nullptr)
            return head->next; // n equals list length

        // while the fast points the last element the slow points one position
        // before the nth element
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // remove the nth element
        if (slow && slow->next)
            slow->next = slow->next->next;

        // return the head
        return head;
    }
};
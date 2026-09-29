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
    ListNode* swapNodes(ListNode* head, int k) {
        // using two pointers

        // first find the left node
        ListNode* left = head;
        for (int i = 1; i < k; i++)
            left = left->next;

        // now to find the right kth node
        ListNode* fast = head;

        // Move fast k nodes ahead.
        // This creates a gap of k nodes between fast and right.
        // When fast reaches nullptr, right will be at the kth node
        // from the end.
        for (int i = 0; i < k; i++)
            fast = fast->next;

        ListNode* right = head;
        while (fast) {
            right = right->next;
            fast = fast->next;
        }

        // now swap both
        int temp = left->val;
        left->val = right->val;
        right->val = temp;

        return head;
    }
};
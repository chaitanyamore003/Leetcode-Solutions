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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = new ListNode(0);
        ListNode* i = ans;
        int carry = 0;
        while (temp1 || temp2) {
            int sum = 0;
            if (temp1)
                sum += temp1->val;
            if (temp2)
                sum += temp2->val;
            sum += carry;
            carry = 0;

            ListNode* add = new ListNode(sum % 10);
            i->next = add;
            carry = sum / 10;

            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
            i = i->next;
        }
        if (carry) {
            ListNode* add1 = new ListNode(carry);
            i->next = add1;
        }

        return ans->next;
    }
};
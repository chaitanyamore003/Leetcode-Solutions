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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        // first reverse the list
        ListNode* temp = reverseList(head);

        // retain the head of the list
        ListNode* reversedHead = temp;

        // now create the list with value doubled
        int carry = 0;
        while (temp) {
            int sum = carry;
            sum += (temp->val * 2);
            temp->val = sum % 10;
            carry = sum / 10;
            temp = temp->next;
        }

        //attach the carry if left
        if (carry) {
            ListNode* node = new ListNode(carry);
            ListNode* tail = reversedHead;

            while (tail->next) {
                tail = tail->next;
            }

            tail->next = node;
        }

        // now reverse it again
        return reverseList(reversedHead);
    }
};
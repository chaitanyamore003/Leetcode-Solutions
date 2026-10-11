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
    ListNode* doubleIt(ListNode* head) {
        // 1st approach
        // 1 --> traverse on the list and fill the elements in the stack to use
        // LIFO 2 --> build the list by doubling the values in stack 3 --> but
        // the list will be in reversed order 4 --> reverse the list and return
        // the head of reversed list

        ListNode* temp = head;
        stack<int> st;
        // filling values in stack
        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        // buidling the list by doubling the number
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;

        while (!st.empty()) {
            int sum = carry;
            sum += (st.top() * 2);
            st.pop();
            ListNode* value = new ListNode(sum % 10);
            t->next = value;
            t = t->next;
            carry = sum / 10;
        }

        if (carry) {
            ListNode* value = new ListNode(carry);
            t->next = value;
        }

        // the list is created but the list needs to be reversed
        t = dummy->next;

        ListNode* prev = nullptr;
        while (t) {
            ListNode* nextEle = t->next;
            t->next = prev;
            prev = t;
            t = nextEle;
        }

        // return the reveresed list
        ListNode* ans = prev;
        delete dummy;
        return ans;
    }
};
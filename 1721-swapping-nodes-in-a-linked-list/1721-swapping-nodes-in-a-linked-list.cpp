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
    int getLen(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLen(head);

        ListNode* l = head;
        int i = 1;

        // left pointer
        while (i < k) {
            l = l->next;
            i++;
        }

        i = n;
        ListNode* r = head;
        // right pointer
        while (i > k) {
            r = r->next;
            i--;
        }

        if(!r || !l) return nullptr;

        
        int temp = l->val;
        l->val = r->val;
        r->val = temp;

        return head;
    }
};
class Solution {
private:
    int getLen(ListNode* head) {
        int cnt = 0;

        while (head) {
            cnt++;
            head = head->next;
        }

        return cnt;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getLen(head);

        int base = n / k;
        int extra = n % k;

        vector<ListNode*> ans;

        ListNode* temp = head;

        for (int i = 0; i < k; i++) {

            // Start of current part
            ans.push_back(temp);

            // Current part gets one extra node
            // if extra > 0
            int size = base + (extra > 0 ? 1 : 0);

            extra--;

            // Move to the last node of this part
            for (int j = 1; j < size && temp; j++) {
                temp = temp->next;
            }

            // Disconnect current part
            if (temp) {
                ListNode* nextPart = temp->next;
                temp->next = nullptr;
                temp = nextPart;
            }
        }

        return ans;
    }
};
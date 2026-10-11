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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // the list length should be atleast 4 to have 2 critical points
        if (!head || !head->next || !head->next->next ||
            !head->next->next->next) {
            return {-1, -1};
        }

        // to track a critical point
        ListNode* curr = head->next;
        ListNode* prev = head;

        // position
        int pos = 1;

        // to track the positions of critical points
        vector<int> positions;

        while (curr->next) {
            // local maxima and local minima
            if ((curr->val > curr->next->val && curr->val > prev->val) ||
                (curr->val < curr->next->val && curr->val < prev->val)) {
                positions.push_back(pos);
            }

            // move the pointers
            prev = curr;
            curr = curr->next;
            pos++;
        }

        // if critical points are less then 2
        if (positions.size() < 2)
            return {-1, -1};

        // now calculate the minimum and maximum distance
        // maximum distance
        int maximum = positions[positions.size() - 1] - positions[0];

        // minimum distance
        int minimum = INT_MAX;
        for (int i = 1; i < positions.size(); i++) {
            minimum = min(positions[i] - positions[i - 1], minimum);
        }

        // return the ans
        return {minimum, maximum};
    }
};
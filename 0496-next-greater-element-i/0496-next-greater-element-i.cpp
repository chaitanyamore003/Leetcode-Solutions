class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> nge;

        for (int i = n2 - 1; i >= 0; i--) {
            int curr = nums2[i];

            // remove all the smaller elements
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // if stack is empty add -1 else top element
            nge[nums2[i]] = st.empty() ? -1 : st.top();

            // add curr element to stack
            st.push(curr);
        }

        vector<int> ans(n1, 0);
        for (int i = 0; i < n1; i++) {
            ans[i] = nge[nums1[i]];
        }
        return ans;
    }
};
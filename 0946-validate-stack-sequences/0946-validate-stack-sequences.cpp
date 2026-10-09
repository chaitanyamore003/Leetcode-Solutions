class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = popped.size();

        int i = 0;
        for (auto it : pushed) {
            st.push(it);

            while (i < n && !st.empty() && popped[i] == st.top()) {
                st.pop();
                i++;
            }
        }

        return st.empty();
    }
};
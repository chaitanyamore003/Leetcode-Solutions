class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char> st;
        for (auto it : s)
            st.push(it);

        int i = t.size() - 1;

        while (i >= 0) {
            if (!st.empty() && t[i] == st.top()) {
                st.pop();
            }
            i--;
        }
        return st.empty();
    }
};
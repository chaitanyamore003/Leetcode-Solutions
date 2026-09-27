class Solution {
public:
    string reverseParentheses(string s) {
        string temp = "";
        stack<string> st;

        for (auto it : s) {
            if (it == '(') {
                st.push(temp);
                temp = "";
            } else if (it == ')') {
                string prev = st.empty() ? "" : st.top();
                if (!st.empty())
                    st.pop();
                reverse(temp.begin(), temp.end());
                temp = prev + temp;
            } else {
                temp += it;
            }
        }
        return temp;
    }
};
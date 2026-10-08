class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        string inside = "";
        int open = 0, close = 0;

        for (auto it : s) {
            if (it == '(' && open == close) {
                ans += inside;
                inside = "";
                close = 0;
                open = 1;
            } else if (it == '(') {
                open++;
                inside += it;
            } else if (it == ')') {
                close++;
                if (close < open)
                    inside += it;
            }
        }
        ans += inside;
        return ans;
    }
};
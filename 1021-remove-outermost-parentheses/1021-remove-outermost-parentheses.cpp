class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0; // Tracks the current nesting level

        string ans = "";

        for (auto it : s) {

            if (it == '(') {

                // If depth > 0, this '(' is not the outermost
                if (depth > 0)
                    ans += it;

                // Increase depth after processing '('
                depth++;

            } else {

                // Decrease depth before processing ')'
                depth--;

                // If depth > 0, this ')' is not the outermost
                if (depth > 0)
                    ans += it;
            }
        }

        return ans;
    }
};
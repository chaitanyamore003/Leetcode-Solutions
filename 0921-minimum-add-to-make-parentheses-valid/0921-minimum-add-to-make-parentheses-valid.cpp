class Solution {
public:
    int minAddToMakeValid(string s) {
        // both show unmatched brackets
        int open = 0, close = 0;

        for (auto it : s) {
            if (it == '(')
                open++;
            else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }

        return open + close;
    }
};
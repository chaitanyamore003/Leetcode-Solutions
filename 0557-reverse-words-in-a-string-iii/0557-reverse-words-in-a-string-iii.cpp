class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            // skipping spaces
            while (i < n && s[i] == ' ')
                i++;

            int l = i;
            // tracking word
            while (i < n && s[i] != ' ')
                i++;

            // reversing the word
            reverse(s.begin() + l, s.begin() + i);
        }
        return s;
    }
};
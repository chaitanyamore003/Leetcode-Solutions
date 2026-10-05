class Solution {
private:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
};
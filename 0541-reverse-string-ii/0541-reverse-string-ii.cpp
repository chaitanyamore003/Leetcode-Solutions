class Solution {
private:
    void revStr(string& s, int l, int r) {
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += (2 * k)) {
            revStr(s, i, min(i + k - 1, n - 1));
        }
        return s;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52, 0);

        for (auto& it : s) {
            if (it < 97) { // upper case
                freq[it - 'A' + 26]++;
            } else { // lower case
                freq[it - 'a']++;
            }
        }

        bool singleTaken = false;
        int ans = 0;
        for (int i = 0; i < 52; i++) {
            if (freq[i] & 1) {
                if (singleTaken == false) { // take odd freq once
                    ans += freq[i];
                    singleTaken = true;
                } else {
                    ans += (freq[i] - 1); // only take even part
                }
            } else {
                ans += freq[i]; // take all even freq
            }
        }

        return ans;
    }
};
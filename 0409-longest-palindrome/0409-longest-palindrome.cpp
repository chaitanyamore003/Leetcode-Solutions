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

        bool hasOdd = false;
        int ans = 0;
        for (int i = 0; i < 52; i++) {
            if (freq[i] & 1) {
                hasOdd = true;
                ans += (freq[i] - 1); // only take the even part
            } else {
                ans += freq[i]; // take all even freq
            }
        }

        // take one odd freq
        if (hasOdd)
            ans++;

        return ans;
    }
};
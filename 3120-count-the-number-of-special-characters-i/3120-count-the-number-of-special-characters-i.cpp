class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> chars(52, 0);

        for (auto it : word) {
            if (islower(it))
                chars[it - 'a']++;
            else
                chars[it - 'A' + 26]++;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (chars[i] > 0 && chars[i + 26] > 0)
                cnt++;
        }
        return cnt;
    }
};
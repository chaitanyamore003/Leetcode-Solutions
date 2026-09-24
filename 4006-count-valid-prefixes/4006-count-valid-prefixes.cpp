class Solution {
public:
    int countValidPrefixes(string s) {
        int zeros = 0, ones = 0;

        int cnt = 0;
        for (auto it : s) {
            if (it == '0')
                zeros++;
            else
                ones++;

            // can be arranged
            if (zeros == ones)
                cnt++;
            else if (zeros == ones + 1)
                cnt++;
            else if (ones == zeros + 1)
                cnt++;
        }
        return cnt;
    }
};
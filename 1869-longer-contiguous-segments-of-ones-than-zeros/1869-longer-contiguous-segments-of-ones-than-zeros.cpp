class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0;
        int streak1 = 0, streak0 = 0;

        for (auto it : s) {
            if (it == '1') {
                ones++;
                zeros = 0;
            } else {
                ones = 0;
                zeros++;
            }

            streak1 = max(streak1, ones);
            streak0 = max(streak0, zeros);
        }

        return streak1 > streak0;
    }
};
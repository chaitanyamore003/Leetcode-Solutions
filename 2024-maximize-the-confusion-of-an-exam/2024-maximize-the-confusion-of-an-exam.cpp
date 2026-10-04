class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int t = 0, f = 0;

        int ans = 0;
        // trying a variable size sliding window to find window with atmost k
        // false
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (answerKey[r] == 'T')
                t++;
            else
                f++;

            while (f > k) {
                if (answerKey[l] == 'F')
                    f--;
                else
                    t--;
                l++;
            }

            ans = max(ans, t + f);
        }

        t = f = 0;
        // same for false
        int p = 0;
        for (int q = 0; q < n; q++) {
            if (answerKey[q] == 'T')
                t++;
            else
                f++;

            while (t > k) {
                if (answerKey[p] == 'F')
                    f--;
                else
                    t--;
                p++;
            }

            ans = max(ans, t + f);
        }

        return ans;
    }
};
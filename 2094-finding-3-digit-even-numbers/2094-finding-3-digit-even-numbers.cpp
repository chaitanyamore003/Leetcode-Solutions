class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        vector<int> ans;

        for (auto it : digits)
            freq[it]++;

        for (int i = 1; i < 10; i++) {
            if (freq[i] == 0)
                continue;

            freq[i]--;

            for (int j = 0; j < 10; j++) {
                if (freq[j] == 0)
                    continue;

                freq[j]--;

                for (int k = 0; k < 10; k += 2) {
                    if (freq[k] == 0)
                        continue;

                    ans.push_back(((i * 100) + (j * 10) + k));
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return ans;
    }
};
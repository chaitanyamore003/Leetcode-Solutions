class Solution {
public:
    string greatestLetter(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (auto it : s) {
            if (islower(it))
                lower[it - 'a']++;
            else
                upper[it - 'A']++;
        }

        for (int i = 25; i >= 0; i--) {
            if (lower[i] > 0 && upper[i] > 0){
                string ans = "";
                ans += (i+'A');
                return ans;
            }
        }
        return "";
    }
};
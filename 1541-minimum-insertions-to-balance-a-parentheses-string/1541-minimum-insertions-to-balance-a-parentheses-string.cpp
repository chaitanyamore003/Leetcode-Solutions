class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int i = 0;
        int cnt = 0;
        int ans = 0; // insertions

        while (i < n) {
            // if opening bracket increase cnt and pointer
            if (s[i] == '(') {
                cnt++;
                i++;
            } else {
                // if there exist opening for this closing bracket then reduce
                // cnt
                if (cnt > 0) {
                    cnt--;
                } else {
                    ans++; // insert opening bracket
                }

                // there are two closing for one opening brackets
                if (i + 1 < n && s[i + 1] == ')')
                    i += 2;
                else {
                    ans++; // inserting ')'
                    i++;
                }
            }
        }

        if (cnt > 0)
            ans += (cnt * 2); // number of opening brackets x 2
        return ans;
    }
};
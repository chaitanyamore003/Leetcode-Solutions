class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.size();
        int n = t.size();
        // traversing from backwards
        int i = m - 1;
        int j = n - 1;

        // make sure both the strings are processed
        while (i >= 0 || j >= 0) {

            // to keep the track of skipping
            int skipS = 0;
            int skipT = 0;

            // finding valid character in string s
            while (i >= 0) {
                // '#' means the previous valid character should be skipped
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else
                    break; // valid character found
            }

            // same for string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else
                    break;
            }

            // if any one string is finished return false
            if ((i >= 0) != (j >= 0))
                return false;

            // if characters don't match return false
            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;

            // move pointers
            i--;
            j--;
        }

        return true;
    }
};
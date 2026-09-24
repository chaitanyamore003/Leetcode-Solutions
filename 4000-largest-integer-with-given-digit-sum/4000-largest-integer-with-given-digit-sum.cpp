class Solution {
public:
    int largestInteger(int n, int s) {

        // If s is impossible to achieve, return -1
        if (s > n * 9)
            return -1;

        // To store the answer
        int ans = 0;

        // Run until all n digits are constructed
        for (int i = 0; i < n; i++) {

            // To create the largest integer,
            // take the largest possible digit
            int digit = min(9, s);

            // Build the answer
            ans = ans * 10 + digit;

            // Remove the selected digit's contribution
            s -= digit;
        }

        return ans;
    }
};
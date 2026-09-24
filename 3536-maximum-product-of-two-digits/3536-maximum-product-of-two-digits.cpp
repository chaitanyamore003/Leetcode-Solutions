class Solution {
public:
    int maxProduct(int n) {
        int digit1 = INT_MIN;
        int digit2 = INT_MIN;

        while (n) {
            int d = n % 10;
            if (d > digit1) {
                digit2 = digit1;
                digit1 = d;
            } else if (d > digit2) {
                digit2 = d;
            }

            n /= 10;
        }

        return digit1 * digit2;
    }
};
class Solution {
private:
    int getDigitsSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int largestInteger(int n, int s) {
        int e = pow(10, n)-1;

        while (e >= 0) {
            if (getDigitsSum(e) == s)
                return e;
            e--;
        }
        return -1;
    }
};
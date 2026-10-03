class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int i = 2;
        int a = 0;
        int b = 1;
        while (i <= n) {
            int sum = a + b;
            a = b;
            b = sum;
            i++;
        }
        return b;
    }
};
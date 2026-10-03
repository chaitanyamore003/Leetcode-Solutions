class Solution {
private:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0;
        int digitSum = 0;

        for (auto it : nums) {
            eleSum += it;
            digitSum += getSum(it);
        }
        return eleSum - digitSum;
    }
};
class Solution {
private:
    int getDigitsSum(int n) {
        if (n == 0)
            return 0;
        return n % 10 + getDigitsSum(n / 10);
    }

public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (getDigitsSum(nums[i]) == i)
                return i;
        }

        return -1;
    }
};
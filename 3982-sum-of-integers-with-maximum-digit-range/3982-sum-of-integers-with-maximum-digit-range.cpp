class Solution {
private:
    int digitRange(int n) {
        int s = 9;
        int l = 0;

        while (n) {
            int digit = n % 10;
            s = min(digit, s);
            l = max(digit, l);
            n /= 10;
        }
        return l - s;
    }

public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        // to track the maxRange
        int maxRange = 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int range = digitRange(nums[i]);

            if (range > maxRange) {
                maxRange = range;
                ans = nums[i];
            } else if (range == maxRange) {
                ans += nums[i];
            }
        }

        return ans;
    }
};
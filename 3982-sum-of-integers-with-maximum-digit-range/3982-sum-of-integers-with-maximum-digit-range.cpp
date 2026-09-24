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
        //to track the maxRange
        int maxRange = 0;

        //to store the nums[i] and its range
        vector<pair<int, int>> ranges(n);

        for (int i = 0; i < n; i++) {
            int range = digitRange(nums[i]);
            maxRange = max(maxRange, range);

            ranges[i] = {nums[i], range};
        }

        int ans = 0;
        //add the elements with max Range
        for (auto it : ranges) {
            if (it.second == maxRange)
                ans += it.first;
        }

        return ans;
    }
};
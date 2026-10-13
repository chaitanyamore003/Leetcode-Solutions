class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(),
             [](int a, int b) { 
                return 1LL * a * a < 1LL * b * b;
             });

        long long ans = 0;
        int mid = n / 2;

        for (int i = 0; i < mid; i++) {
            ans -= 1LL * nums[i] * nums[i];
            ans += 1LL * nums[mid + i] * nums[mid + i];
        }

        if (n & 1) {
            ans += 1LL * nums[n - 1] * nums[n - 1];
        }
        return ans;
    }
};
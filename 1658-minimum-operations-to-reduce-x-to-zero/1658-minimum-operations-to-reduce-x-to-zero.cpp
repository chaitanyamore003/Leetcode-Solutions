class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for (auto& it : nums)
            total += it;

        if(x > total) return -1;
        int remaining = total - x;

        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (l < n && sum > remaining) {
                sum -= nums[l];
                l++;
            }

            if (sum == remaining)
                ans = min(ans, n - (r - l + 1));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
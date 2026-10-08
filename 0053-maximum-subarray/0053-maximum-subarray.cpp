class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kadane's algorithm

        int sum = 0;
        int ans = INT_MIN;
        for (auto it : nums) {
            sum += it;
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
};
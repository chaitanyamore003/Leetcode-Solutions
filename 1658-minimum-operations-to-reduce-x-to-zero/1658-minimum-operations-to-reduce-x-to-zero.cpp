class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        //approach - instead of finding the operations to reduce x to zero
        //we find a the window of remaining sum and subtract its size from total to get 
        // the number of minimum operations needed
        int total = 0;
        for (auto& it : nums)
            total += it;

        //if x is greater then total we cannot find the remining sum
        if(x > total) return -1;
        int remaining = total - x;

        //we used the variable size sliding window
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            //expand the window
            sum += nums[r];

            //shrinking the window
            while (l < n && sum > remaining) {
                sum -= nums[l];
                l++;
            }

            //if current window satisfies the condition we get the minimum ans stored
            if (sum == remaining)
                ans = min(ans, n - (r - l + 1));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
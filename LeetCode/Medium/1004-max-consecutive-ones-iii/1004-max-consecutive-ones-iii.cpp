class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // we create a variable size sliding window to track frequencies or zero
        // if current sliding window has k number of zero's then we can convert
        // them to ones
        int n = nums.size();
        int l = 0; // left
        int zeros = 0;
        int ans = 0;

        // r -> right
        for (int r = 0; r < n; r++) {
            //expand the window 
            if (nums[r] == 0)
                zeros++;

            //shrink the window
            while (zeros > k) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            //get the size of a valid window
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
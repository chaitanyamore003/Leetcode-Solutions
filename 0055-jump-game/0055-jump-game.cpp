class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // farthest we can reach with each jump
        int farthest = 0;

        for (int i = 0; i < n; i++) {

            // we cannot reach the ith index
            if (i > farthest)
                return false;

            farthest = max(farthest, i + nums[i]);

            if (farthest >= n)
                return true;
        }
        return true;
    }
};
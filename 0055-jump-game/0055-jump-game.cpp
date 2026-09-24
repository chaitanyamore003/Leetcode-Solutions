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
            

            //determining how far we can jump from here
            farthest = max(farthest, i + nums[i]);

            //if we can jump pass the array return true
            if (farthest >= n)
                return true;
        }

        //we reached the last
        return true;
    }
};
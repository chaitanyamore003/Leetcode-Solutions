class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 2;

        // finding the breakpoint
        while (i >= 0) {
            if (nums[i] < nums[i + 1])
                break;
            i--;
        }

        // array is at it's last permutation
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // finding the first greater element from right
        int j = n - 1;
        while (j >= 0) {
            if (nums[j] > nums[i])
                break;
            j--;
        }

        // swapping both
        swap(nums[i], nums[j]);

        // reversing the second half
        reverse(nums.begin() + i + 1, nums.end());
    }
};
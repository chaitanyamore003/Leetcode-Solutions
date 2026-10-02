class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            int n = nums.size();

            vector<int> newNums(n / 2);

            for (int i = 0; i < n / 2; i++) {
                if (i & 1)
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                else
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            nums = newNums;
        }
        return nums[nums.size() - 1];
    }
};
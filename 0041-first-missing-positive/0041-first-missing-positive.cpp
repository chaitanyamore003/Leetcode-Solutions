class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i < n) {
            if (nums[i] >= 1 && nums[i] <= n) {
                int correct = nums[i] - 1;
                if (nums[correct] != nums[i]) {
                    swap(nums[i], nums[correct]);

                } else
                    i++; //already on correct position no swap needed
            } else
                i++; //element not in range
        }

        for (int k = 0; k < n; k++) {
            if (nums[k] != k + 1)
                return k + 1;
        }
        return n+1;
    }
};
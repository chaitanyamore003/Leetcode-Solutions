class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        vector<int> squares(n, 0);
        int i = n-1;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                squares[i--] = (nums[l] * nums[l]);
                l++;
            } else {
                squares[i--] = (nums[r] * nums[r]);
                r--;
            }
        }
        return squares;
    }
};
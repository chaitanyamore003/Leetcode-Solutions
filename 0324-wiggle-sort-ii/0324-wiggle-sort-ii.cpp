class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int r = n - 1;
        int mid = (n-1)/2;

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                ans[i] = nums[r--];
            } else {
                ans[i] = nums[mid--];
            }
        }

        nums = ans;
    }
};
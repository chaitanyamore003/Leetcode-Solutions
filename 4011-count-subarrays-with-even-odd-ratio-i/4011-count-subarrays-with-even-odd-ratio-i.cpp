class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        int even = 0, odd = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            even = 0;
            odd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1)
                    odd++;
                else
                    even++;

                if (odd && (even * b <= odd * a))
                    cnt++;
            }
        }

        return cnt;
    }
};
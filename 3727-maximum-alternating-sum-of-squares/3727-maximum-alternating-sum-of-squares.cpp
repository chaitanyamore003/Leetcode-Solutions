class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) < abs(b); });

        vector<int> lesser, greater;
        int mid = n / 2;

        // storing lesser elements
        for (int i = 0; i < mid; i++) {
            lesser.push_back(nums[i]);
        }

        // storing greater elements
        for (int i = mid; i < n; i++) {
            greater.push_back(nums[i]);
        }

        // calculating answer
        long long ans = 0;

        int k = 0;
        int l = 0;

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                ans -= (lesser[k] * lesser[k]);
                k++;
            } else {
                ans += (greater[l] * greater[l]);
                l++;
            }
        }

        return ans;
    }
};
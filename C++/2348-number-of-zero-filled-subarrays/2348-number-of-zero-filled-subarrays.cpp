class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;

        for (auto it : nums) {
            if (it)
                cnt = 0;
            else
                cnt++;

            ans += cnt;
        }
        return ans;
    }
};
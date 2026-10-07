class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans;
        for (int i = 1; i < INT_MAX; i++) {
            if (!st.count(i)) {
                ans = i;
                break;
            }
        }
        st = {};
        return ans;
    }
};
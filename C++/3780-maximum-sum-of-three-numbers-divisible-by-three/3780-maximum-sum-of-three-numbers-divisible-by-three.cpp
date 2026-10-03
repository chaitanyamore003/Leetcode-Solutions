class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> v(3);

        for (auto it : nums) {
            v[it % 3].push_back(it);
        }
        int ans = 0;
        for (auto& it : v) {
            sort(it.begin(), it.end(), greater<int>());
        }

        // zero
        if (v[0].size() >= 3)
            ans = max(ans, v[0][0] + v[0][1] + v[0][2]);

        // one
        if (v[1].size() >= 3)
            ans = max(ans, v[1][0] + v[1][1] + v[1][2]);

        // two
        if (v[2].size() >= 3)
            ans = max(ans, v[2][0] + v[2][1] + v[2][2]);

        //012
        if (v[0].size() >= 1 && v[1].size() >= 1 && v[2].size() >= 1) {
            ans = max(ans, v[0][0] + v[1][0] + v[2][0]);
        }
        return ans;
    }
};
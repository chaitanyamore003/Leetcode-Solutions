class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // optimal
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (auto it : st) {

            // there is no lesser element
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int currNum = it;
                while (st.count(currNum + 1)) {
                    currNum++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
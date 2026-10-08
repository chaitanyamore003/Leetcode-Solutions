class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;

        // more optimal
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total == 0) {
                    ans.insert({nums[i], nums[l], nums[r]});

                    //search for more triplets for same i position
                    l++;
                    r--;
                } else if (total < 0)
                    l++;
                else
                    r--;
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
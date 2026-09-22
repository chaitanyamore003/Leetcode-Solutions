using vi = vector<int>;
using ss = set<vi>;
class Solution {
    vi ds;
    ss ans;

private:
    void getSubSets(vi& nums, vi& ds, ss& ans, int i, int n) {
        if (i == n) {
            ans.insert(ds);
            return;
        }

        // add the current element
        ds.push_back(nums[i]);
        getSubSets(nums, ds, ans, i + 1, n);

        // backtracking
        // remove the current element
        ds.pop_back();
        getSubSets(nums, ds, ans, i + 1, n);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ds.clear();
        ans.clear();
        int n = nums.size();
        sort(nums.begin(), nums.end());
        getSubSets(nums, ds, ans, 0, n);
        return vector<vi>(ans.begin(), ans.end());
    }
};
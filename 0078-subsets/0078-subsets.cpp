using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
private:
    vi ds;
    vvi ans;

private:
    void getSubSets(vi& nums, vi& ds, vvi& ans, int i, int n) {
        if (i == n) {
            ans.push_back(ds);
            return;
        }

        // take this elment
        ds.push_back(nums[i]);
        getSubSets(nums, ds, ans, i + 1, n);

        // not take this element
        ds.pop_back();
        getSubSets(nums, ds, ans, i + 1, n);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // using backtracking

        int n = nums.size();
        getSubSets(nums, ds, ans, 0, n);
        return ans;
    }
};
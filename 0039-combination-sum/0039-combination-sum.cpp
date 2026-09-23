using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
private:
    void getCombinations(int i, int n, int target, vi& arr, vi& ds, vvi& ans) {
        if (i == n) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick case

        // 1 -> we cannot take more of these elements
        if (target >= 0) {
            ds.push_back(arr[i]);
            getCombinations(i, n, target - arr[i], arr, ds, ans);

            // we reach the end of this tree
            ds.pop_back();
        }

        // non pick case
        getCombinations(i + 1, n, target, arr, ds, ans);
    }

public:
    vvi combinationSum(vi& candidates, int target) {
        vi ds;
        vvi ans;
        getCombinations(0, candidates.size(), target, candidates, ds, ans);
        return ans;
    }
};
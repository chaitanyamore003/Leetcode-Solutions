using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
private:
    void getCombinations(int i, int n, int target, vi& arr, vi& ds, vvi& ans) {

        // Base case:
        // We have considered all the elements.
        if (i == n) {

            // If remaining target becomes 0,
            // current combination is a valid answer.
            if (target == 0) {
                ans.push_back(ds);
            }

            return;
        }

        // PICK CASE
        //
        // We can pick the current element only when
        // the remaining target is still non-negative.
        //
        // We keep 'i' same because in Combination Sum,
        // an element can be picked multiple times.
        if (target >= arr[i]) {

            // Pick the current element.
            ds.push_back(arr[i]);

            // Reduce the target by the value we picked.
            // Keep i same -> current element can be reused.
            getCombinations(i, n, target - arr[i], arr, ds, ans);

            // Backtrack:
            // Remove the element we picked so that we can
            // explore the non-pick branch with the original ds.
            ds.pop_back();
        }

        // NON-PICK CASE
        //
        // Do not pick arr[i].
        // Move to the next element.
        //
        // target remains unchanged because we did not
        // select anything.
        getCombinations(i + 1, n, target, arr, ds, ans);
    }

public:
    vvi combinationSum(vi& candidates, int target) {

        // Stores the current combination being built.
        vi ds;

        // Stores all valid combinations.
        vvi ans;

        // Start from index 0.
        getCombinations(0, candidates.size(), target, candidates, ds, ans);

        return ans;
    }
};

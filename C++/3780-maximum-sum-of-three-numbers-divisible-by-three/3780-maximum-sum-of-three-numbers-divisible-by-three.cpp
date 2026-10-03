class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> zero, one, two;

        for (auto& it : nums) {
            if (it % 3 == 0)
                zero.push_back(it);
            else if (it % 3 == 1)
                one.push_back(it);
            else
                two.push_back(it);
        }

        // sort all
        sort(zero.rbegin(), zero.rend());
        sort(one.rbegin(), one.rend());
        sort(two.rbegin(), two.rend());

        int ans = 0;

        if (zero.size() >= 3) {
            ans = max(ans, (zero[0] + zero[1] + zero[2]));
        };

        if (one.size() >= 3) {
            ans = max(ans, (one[0] + one[1] + one[2]));
        };

        if (two.size() >= 3) {
            ans = max(ans, (two[0] + two[1] + two[2]));
        };

        if (zero.size() >= 1 && one.size() >= 1 && two.size() >= 1) {
            ans = max(ans, (zero[0] + one[0] + two[0]));
        }

        return ans;
    }
};
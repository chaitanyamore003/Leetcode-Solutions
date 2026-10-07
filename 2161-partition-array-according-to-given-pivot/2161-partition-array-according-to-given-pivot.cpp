class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less = 0, equal = 0;

        for (auto it : nums) {
            if (it < pivot)
                less++;
            else if (it == pivot)
                equal++;
        }

        int i = 0;
        int j = less;
        int k = less + equal;

        vector<int> ans(n);
        for (auto it : nums) {
            if (it < pivot)
                ans[i++] = it;
            else if (it == pivot)
                ans[j++] = it;
            else
                ans[k++] = it;
        }

        
        return ans;
    }
};
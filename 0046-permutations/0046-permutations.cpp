class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // storing temp to find next permutation
        vector<int> temp = nums;
        next_permutation(temp.begin(), temp.end());

        // to store the final answer
        vector<vector<int>> ans;
        ans.push_back(nums);

        // stop if all permutations are processed
        while (temp != nums) {
            ans.push_back(temp);

            // find next permutation
            next_permutation(temp.begin(), temp.end());
        }
        return ans;
    }
};
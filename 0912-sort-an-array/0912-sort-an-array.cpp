class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        // creating a bucket
        vector<int> bucket(maxi - mini + 1, 0);

        // filling the bucket
        for (auto it : nums) {
            bucket[it - mini]++;
        }

        vector<int> ans;

        // emptying the bucket
        for (int i = 0; i < bucket.size(); i++) {
            while (bucket[i]--) {
                ans.push_back(i + mini);
            }
        }

        // return sorted array
        return ans;
    }
};
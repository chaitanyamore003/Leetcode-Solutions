class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int diff = 0;

        for(auto it : nums){
            mini = min(mini, it);
            diff = max(diff, it - mini);
        }
        return diff == 0 ? -1 : diff;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> seen;

        for(int i = 0; i < n; i++){
            int ele = target - nums[i];
            if(!seen.empty() && seen.count(ele)){
                return {seen[ele], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
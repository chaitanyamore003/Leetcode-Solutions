class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            if (i & 1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());

        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1)
                nums[i] = odd[b++];
            else
                nums[i] = even[a++];
        }
        return nums;
    }
};
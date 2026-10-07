class Solution {
private:
    bool canSplit(vector<int>& arr, int sum, int k) {
        // sum
        int s = 0;
        // parts
        int p = 1;

        for (auto it : arr) {
            if (s + it <= sum)
                s += it;
            else {
                s = it;
                p++;
            }
        }

        // can split
        return p <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        // minimum -> minimized maximum sum
        int s = 0;

        // maximum -> minimized maximum sum
        int e = 0;

        for (auto it : nums) {
            // maximum element
            s = max(s, it);
            // sum of all elements
            e += it;
        }

        int ans = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            //if array can be split in k parts in this sum try to minimize it
            if (canSplit(nums, mid, k)) {
                ans = mid;
                e = mid - 1;
            } else //if cannot split increase the sum
                s = mid + 1;
        }
        return ans;
    }
};
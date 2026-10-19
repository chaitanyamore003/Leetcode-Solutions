class Solution {
private:
    int getPos(vector<int>& arr, int t, bool checkLeft) {
        int s = 0;
        int e = arr.size() - 1;

        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == t) {
                ans = mid;
                if (checkLeft) {
                    e = mid - 1;
                } else
                    s = mid + 1;
            } else if (arr[mid] < t)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return ans;
    }

public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int firstOcc = getPos(nums, target, true);
        int lastOcc = getPos(nums, target, false);

        vector<int> ans;
        if (firstOcc == -1)
            return ans;
        for (int i = firstOcc; i <= lastOcc; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
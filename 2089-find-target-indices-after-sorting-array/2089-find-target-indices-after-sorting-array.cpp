class Solution {
private:
    int getPos(vector<int>& arr, int t, bool searchLeft) {
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == t) {
                ans = mid;
                if (searchLeft)
                    e = mid - 1;
                else
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
        sort(nums.begin(), nums.end());
        int first = getPos(nums, target, true);
        if(first == -1) return {};
        int last = getPos(nums, target, false);

        vector<int> ans;
        for (int i = first; i <= last; i++)
            ans.push_back(i);
        return ans;
    }
};
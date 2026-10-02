class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int maxi = -1;

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;
        int ans = 0;

        while (l < r) {
            int h = min(height[l], height[r]);
            int w = r - l;

            ans = max(ans, h * w);

            // we try to get maximum, min height so the overall height could be
            // higher but for better height we sacrifice width
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
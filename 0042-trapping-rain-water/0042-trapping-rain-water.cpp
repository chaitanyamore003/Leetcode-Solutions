class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // left wall helps blocking water from left and same for right
        int leftMax = 0;
        int rightMax = 0;
        int l = 0;
        int r = n - 1;
        int water = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            // we have to consider the smaller wall because that is what
            // actually blocks minimum amount of water
            if (height[l] < height[r]) {
                water += leftMax - height[l];
                l++;
            } else {
                water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};
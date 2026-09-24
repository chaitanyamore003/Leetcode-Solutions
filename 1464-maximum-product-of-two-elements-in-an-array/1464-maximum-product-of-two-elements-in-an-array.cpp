class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for (auto it : nums) {
            if (it > max1) {
                max2 = max1;
                max1 = it;
            } else if (it > max2)
                max2 = it;
        }

        return (max1 - 1) * (max2 - 1);
    }
};
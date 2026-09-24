class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // maximum of 3 elements can be found by 2 ways
        // 1 -> product of 3 maximum elements
        // 2 -> product of 2 minimum and 1 maximum (to make final answer
        // positive)

        int max1 = INT_MIN, max2 = 0, max3 = 0;
        int min1 = INT_MAX, min2 = 0;

        for (auto it : nums) {

            // finding 3 max elements
            if (it > max1) {
                max3 = max2;
                max2 = max1;
                max1 = it;
            } else if (it > max2) {
                max3 = max2;
                max2 = it;
            } else if (it > max3)
                max3 = it;

            // finding 2 minimum elements
            if (it < min1) {
                min2 = min1;
                min1 = it;
            } else if (it < min2) {
                min2 = it;
            }
        }

        int ans = max(max1 * max2 * max3, min1 * min2 * max1);
        return ans;
    }
};
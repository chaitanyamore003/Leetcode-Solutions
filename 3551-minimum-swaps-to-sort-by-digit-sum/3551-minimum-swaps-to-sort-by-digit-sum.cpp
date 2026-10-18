class Solution {
public:
    // Calculates the sum of digits of a number
    static int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10; // Add the last digit
            n /= 10;       // Remove the last digit
        }
        return sum;
    }

    // Custom comparator to sort by digit sum
    // If digit sums are equal, sort by the actual number
    static bool comparator(const int& a, const int& b) {
        int digitSum1 = digitSum(a);
        int digitSum2 = digitSum(b);

        if (digitSum1 == digitSum2)
            return a < b;

        return digitSum1 < digitSum2;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Create a copy of nums and sort it into the required order
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end(), comparator);

        // Store each element's current index in the original array
        unordered_map<int, int> mapp;
        for (int i = 0; i < n; i++) {
            mapp[nums[i]] = i;
        }

        // Count the minimum swaps required
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            // If the current element is not in its correct position
            if (nums[i] != sorted[i]) {

                // Find the current position of the element
                // that should be placed at index i
                int currPos = mapp[sorted[i]];

                // Update the index of the element being moved
                mapp[nums[i]] = currPos;

                // Update the index of the element moving to index i
                mapp[nums[currPos]] = i;

                // Swap the elements to place the correct element at index i
                swap(nums[i], nums[currPos]);

                // Increment the swap count
                cnt++;
            }
        }

        // Return the total number of swaps
        return cnt;
    }
};
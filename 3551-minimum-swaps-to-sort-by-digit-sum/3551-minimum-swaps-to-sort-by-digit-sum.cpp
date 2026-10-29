class Solution {
private:
    static int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    static bool comparator(int& a, int& b) {
        int sumA = digitSum(a);
        int sumB = digitSum(b);
        if (sumA == sumB)
            return a < b;
        else
            return sumA < sumB;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), comparator);

        int swaps = 0;

        unordered_map<int, int> mapp;
        for (int i = 0; i < n; i++) {
            mapp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != sorted[i]) {

                int index = mapp[sorted[i]];
                mapp[nums[i]] = index;
                mapp[nums[index]] = i;
                swap(nums[i], nums[index]);

                swaps++;
            }
        }
        return swaps;
    }
};
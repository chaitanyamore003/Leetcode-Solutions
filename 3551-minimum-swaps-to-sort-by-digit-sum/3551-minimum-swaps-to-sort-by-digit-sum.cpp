class Solution {
public:
    static int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    static bool comparator(const int& a, const int& b) {
        int digitSum1 = digitSum(a);
        int digitSum2 = digitSum(b);
        if (digitSum1 == digitSum2)
            return a < b;
        else
            return digitSum1 < digitSum2;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // ideal sorted array
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end(), comparator);

        // storing the indexes of elements
        unordered_map<int, int> mapp;

        for (int i = 0; i < n; i++) {
            mapp[nums[i]] = i;
        }

        // number of swaps
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != sorted[i]) {
                int currPos = mapp[sorted[i]];
                mapp[nums[i]] = currPos;
                mapp[nums[currPos]] = i;
                swap(nums[i], nums[currPos]);
                cnt++;
            }
        }
        return cnt;
    }
};
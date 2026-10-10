class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();

        // size of array is 10^5 and all set to zero
        vector<int> diffFreq(1e5 + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            diffFreq[d]++;
        }

        // total operations
        long long K = k1 + k2;

        // traverse from backwards
        for (int i = 1e5; i > 0 && K > 0; i--) {
            // maximum operations we can perform
            int countOps = min((int)K, diffFreq[i]);

            // reduce the freq of curr diff
            diffFreq[i] -= countOps;
            // increase the freq of one before index
            diffFreq[i - 1] += countOps;
            // reduce the operations
            K -= countOps;
        }

        //get the final sum of squares of differences
        long long ans = 0;

        for (int i = 1; i <= 1e5; i++) {
            ans += (1LL * diffFreq[i] * (1LL * i * i));
        }
        return ans;
    }
};
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();

        // finding the diff of all n elements
        vector<long long> diff(n, 0);

        // maximum difference so far
        long long maxi = 0;

        for (int i = 0; i < n; i++) {
            long long d = abs(1LL * (nums1[i] - nums2[i]));
            diff[i] = d;
            maxi = max(maxi, d);
        }

        // now we define the vector of size maxi + 1 so we can count the freq of
        // diff

        vector<long long> diffCnt(maxi + 1, 0);

        // filling the vector
        for (int i = 0; i < n; i++) {
            diffCnt[diff[i]]++;
        }

        // total actions we can perform
        long long actions = k1 + k2;

        // now because we want to eleminate larger diff first, we traverse from
        // back
        for (int i = maxi; i > 0; i--) {
            // maximum operations we can perform currently
            long long currAct = min((int)actions, (int)diffCnt[i]);

            // we reduce the current diff
            diffCnt[i] -= currAct;

            // add the diff freq in previos element
            diffCnt[i - 1] += currAct;

            // reduce the actions performed
            actions -= currAct;
        }

        // now finally after all the actions are been performed we calculate the
        // sum
        long long ans = 0;

        for (int i = 1; i <= maxi; i++) {
            // i is the diff
            //and diffCnt[i] is its freq
            long long square = 1LL * diffCnt[i] * (1LL * i * i);

            ans += square;
        }

        return ans;
    }
};
/**
 * @param {number[]} nums
 * @return {number}
 */
var splitArray = function (nums) {
    let n = nums.length;
    if (n == 0) return 0;

    let primes = new Array(n).fill(true);
    primes[0] = primes[1] = false;
    for (let i = 2; i * i <= n; i++) {
        if (primes[i] == true) {
            for (let j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    let sum1 = 0, sum2 = 0;

    for (let i = 0; i < n; i++) {
        if (primes[i]) sum1 += nums[i];
        else sum2 += nums[i];
    }

    return Math.abs(sum1 - sum2);
};
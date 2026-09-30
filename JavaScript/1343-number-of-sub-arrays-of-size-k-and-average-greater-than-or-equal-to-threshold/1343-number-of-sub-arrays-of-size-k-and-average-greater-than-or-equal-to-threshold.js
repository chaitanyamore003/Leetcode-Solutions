/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} threshold
 * @return {number}
 */
var numOfSubarrays = function (arr, k, threshold) {
    let n = arr.length;

    let windowSum = 0;
    for (let i = 0; i < k; i++) windowSum += arr[i];
    let ans = 0;

    if (windowSum >= k * threshold) ans++;

    for (let i = k; i < n; i++) {
        windowSum = windowSum - arr[i - k] + arr[i];

        if (windowSum >= k * threshold) ans++;
    }
    return ans;

};
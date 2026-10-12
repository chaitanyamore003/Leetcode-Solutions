/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
    let n = arr.length;
    let res = new Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = fn(arr[i], i);
    }
    return res;
};
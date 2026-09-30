/**
 * @param {number[]} nums
 * @return {number}
 */

var reverse = function (n) {
    let ans = 0;
    while (n) {
        let digit = n % 10;
        ans = ans * 10 + digit;
        n = Math.floor(n / 10);
    }
    return ans;
}
var countDistinctIntegers = function (nums) {
    let set = new Set();
    for (let i of nums) {
        set.add(i);
        set.add(reverse(i));
    }
    return set.size;
};
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let n = nums.length;

    let l = 2;
    for (let r = 2; r < n; r++) {
        if (nums[r] !== nums[l - 2]) {
            nums[l] = nums[r];
            l++;
        }
    }
    return l;
};
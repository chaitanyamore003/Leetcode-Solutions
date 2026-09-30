/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let n = nums.length;
    let total = 0;

    for(let i = 0; i < n; i++){
        total += nums[i];
    }

    let left = 0;
    for(let i = 0; i < n; i++){
        left += (i == 0 ? 0 : nums[i-1]);
        let right = total - left - nums[i];

        if(left == right) return i;
    }
    return -1;
};
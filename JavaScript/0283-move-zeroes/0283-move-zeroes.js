/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let n = nums.length;
    let l = 0;
    for(let r = 0; r < n; r++){
        if(nums[r] != 0){
            let temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
        }
    }
};
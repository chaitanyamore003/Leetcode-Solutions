/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let n = nums.length;

    let l = 0;
    for(let r = 0; r < n; r++){
        if(nums[r] != val){
            nums[l] = nums[r];
            l++;
        }
    }
    return l;
};
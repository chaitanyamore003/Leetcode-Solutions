/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let n = nums.length;
    let l = 0;
    for(let r = 0; r < n; r++){
        if(nums[r] != nums[l]){
            nums[++l] = nums[r];
        }
    }
    return l+1;
};
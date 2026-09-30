/**
 * @param {number[]} nums
 */
 let prefix = new Array();
var NumArray = function(nums) {
    let n = nums.length;
    this.prefix = new Array(n);

    this.prefix[0] = nums[0];
    for(let i = 1; i < n; i++){
        this.prefix[i] = this.prefix[i-1] + nums[i];
    }
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function(left, right) {
    if(left == 0) return this.prefix[right];
    else return this.prefix[right] - this.prefix[left - 1];
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
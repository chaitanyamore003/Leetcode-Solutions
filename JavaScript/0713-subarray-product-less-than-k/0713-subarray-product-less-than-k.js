/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    if(k <= 1) return 0;
    let n = nums.length;
    let windowProd = 1;
    let l = 0;

    let ans = 0;
    for(let r = 0; r < n; r++){
        //expanding the window
        windowProd *= nums[r];


        //shrinking and making it valid
        while(l < n && windowProd >= k){
            windowProd /= nums[l];
            l++;
        }

        //number of subarrays
        ans += (r-l+1);
    }
    return ans;
};
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function (nums) {
    let freq = new Array(101).fill(0);

    //taking freq of each number
    for (let i of nums) {
        freq[i]++;
    }

    //checking smaller elements for each
    for (let i = 1; i < 101; i++) {
        //because each greater element will smaller elements as summission of all the smaller elements of its one smaller element
        freq[i] += freq[i - 1];
    }

    let ans = new Array();
    for (let i = 0; i < nums.length; i++) {
        if(nums[i])ans.push(freq[nums[i] - 1]);
        else ans.push(0);
    }
    return ans;
};
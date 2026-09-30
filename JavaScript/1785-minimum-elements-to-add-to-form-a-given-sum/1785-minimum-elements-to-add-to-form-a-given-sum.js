/**
 * @param {number[]} nums
 * @param {number} limit
 * @param {number} goal
 * @return {number}
 */
var minElements = function(nums, limit, goal) {
    let total = 0;
    for(let i of nums) total += i;

    let diff = Math.abs(goal - total);

    if(diff % limit == 0) return diff/limit;
    else return Math.ceil(diff/limit);
};
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
    let cnt = 0;
    let streak = 0;

    for (let i of nums) {
        if (i) cnt++;
        else cnt = 0;
        streak = Math.max(streak, cnt);
    }
    return streak;
};
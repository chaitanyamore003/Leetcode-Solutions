/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function getPos(nums, t, checkLeft) {
    let n = nums.length;
    let s = 0;
    let e = n - 1;
    let ans = -1;
    while (s <= e) {
        let mid = Math.floor(s + (e - s) / 2);

        if (nums[mid] == t) {
            ans = mid;
            if (checkLeft) {
                e = mid - 1;
            } else s = mid + 1;
        } else if (nums[mid] > t) e = mid - 1;
        else s = mid + 1;
    }
    return ans;
}


var searchRange = function (nums, target) {
    let first = getPos(nums, target, true);
    let last = getPos(nums, target, false);

    let answer = new Array();
    answer.push(first);
    answer.push(last);

    return answer;
};
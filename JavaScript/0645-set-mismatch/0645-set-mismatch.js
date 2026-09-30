/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function (nums) {
    let n = nums.length;

    let missing = -1, duplicate = -1;

    //finding duplicates
    for (let i = 0; i < n; i++) {
        let num = Math.abs(nums[i]);

        let index = num - 1;

        if (nums[index] < 0) {
            duplicate = num;
        } else {
            nums[index] = -nums[index];
        }
    }

    //finding missing
    for (let i = 0; i < n; i++) {
        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }


    return [duplicate, missing];
};
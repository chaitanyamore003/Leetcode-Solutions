/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    let n = digits.length;

    if (digits[n - 1] < 9) {
        digits[n - 1]++;
        return digits;
    } else {
        let i = n - 1;
        while (i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if (i >= 0) {
            digits[i]++;
            return digits;
        } else {
            digits.unshift(1);
            return digits;
        }
    }
};
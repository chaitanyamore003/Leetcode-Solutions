/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    let ans = 0;
    let temp = Math.abs(x);
    while (temp) {
        let digit = temp % 10;
        ans = ans * 10 + digit;
        temp = Math.floor(temp / 10);
    }
    if (ans > 2147483647) return 0;
    if (x < 0) return -ans;
    return ans;
};
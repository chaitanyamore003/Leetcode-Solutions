/**
 * @param {number} n
 * @return {number[]}
 */
var decimalRepresentation = function (n) {
    let power = 1;
    let ans = new Array();

    while (n) {
        let digit = n % 10;
        if(digit != 0) ans.push(digit * power);
        power *= 10;
        n = Math.floor(n / 10);
    }
    ans.reverse();
    return ans;
};
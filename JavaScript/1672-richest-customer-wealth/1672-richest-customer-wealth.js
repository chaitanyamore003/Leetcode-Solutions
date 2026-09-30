/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function (accounts) {
    let r = accounts.length;
    let c = accounts[0].length;

    let ans = 0;
    for (let i = 0; i < r; i++) {
        let amount = 0;
        for (let j = 0; j < c; j++) {
            amount += accounts[i][j];
        }
        ans = Math.max(ans, amount);
    }
    return ans;
};
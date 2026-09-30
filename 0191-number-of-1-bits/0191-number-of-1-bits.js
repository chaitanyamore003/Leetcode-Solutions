/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    let cnt = 0;
    while(n){
        if(n&1) cnt++;
        n >>= 1;
    }
    return cnt;
};
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let n = s.length;
    let i = n - 1;

    while (i >= 0 && s[i] == ' ') i--;

    let cnt = 0;
    while (i >= 0 && /[a-zA-Z]/.test(s[i])) {
        i--;
        cnt++;
    }
    return cnt;
};
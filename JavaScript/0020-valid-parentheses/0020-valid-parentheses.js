/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    let st = new Array();

    for (let i of s) {
        if (i === '[' || i === '{' || i === '(') {
            st.push(i);

        } else {
            if (st.length == 0) return false;
            let n = st.length;
            if (i === ']' && st[n - 1] != '[') return false;
            else if (i === '}' && st[n - 1] != '{') return false;
            else if (i === ')' && st[n - 1] != '(') return false;
            st.pop();
        }
    }

    return st.length == 0;
};
/**
 * @param {number[]} arr
 * @return {number}
 */
var maximumElementAfterDecrementingAndRearranging = function(arr) {
    arr.sort((a, b) => a-b);
    let n = arr.length;
    arr[0] = 1;
    let maxi = 1;
    for(let i = 1; i < n; i++){
        if((arr[i] - arr[i-1]) > 1){
            arr[i] = arr[i-1] + 1;
        }
        maxi = Math.max(maxi, arr[i]);
    }
    return maxi;
};
/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let n = candies.length;
    let maxCandies = 0;
    for(let i = 0; i < n; i++) maxCandies = Math.max(maxCandies, candies[i]);

    let answer = new Array(n, false);

    for(let i = 0; i < n; i++){
        answer[i] = (candies[i] + extraCandies >= maxCandies);
    }
    return answer;
};
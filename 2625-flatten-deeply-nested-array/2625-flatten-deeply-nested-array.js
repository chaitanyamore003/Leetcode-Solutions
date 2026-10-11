/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    // If depth is 0, no flattening is required
    if (n == 0) return arr;

    // Stores the flattened elements
    let result = [];

    // Recursive helper function to flatten the array
    function flatt(arr, n) {
        for (let i = 0; i < arr.length; i++) {

            // If the current element is an array and depth allows flattening
            if (Array.isArray(arr[i]) && n > 0) {

                // Recursively flatten the nested array with reduced depth
                flatt(arr[i], n - 1);

            } else {
                // Add the element directly to the result
                result.push(arr[i]);
            }
        }
    }

    // Start flattening from the given array and depth
    flatt(arr, n);

    // Return the final flattened array
    return result;
};
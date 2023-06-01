/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans = []
    for(i = 0; i < arr.length; i++) {
        if(fn(arr[i], i)) ans.push(arr[i])
    }
    return ans
};
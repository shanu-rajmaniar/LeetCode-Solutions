/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let x
    class counter {
        constructor(init) {
            x = init;
        }
        increment() {
            init += 1
            return init
        }
        reset() {
            init = x
            return x
        }
        decrement() {
            init -= 1
            return init
        }
    }
    return new counter(init)
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
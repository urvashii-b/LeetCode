/**
 * @return {Function}
 */

/*
BASIC SYNTAX
function f(a,b){
 const sum = a+b;
 return sum;
}
console.log(f(3,4));


ANONYMOUS FUNCTION
var f = function(a,b){
 const sum = a+b;
 return sum;
}
console.log(f(3,4));


Immediately Invoked Function Expression
const res = (function(a,b){
 const sum = a+b;
 return sum;
})(3,4);
console.log(res);


Function Hoisting - use function before it is initialized (bad practice - as there it reduces readability)
function createFunc(){
    return f;
    function f(a,b){
        const sum = a+b;
        return sum;
    }
}
const f = createFunc();
console.log(f(3,4));
*/
var createHelloWorld = function() {
    
    // return function(...args) {
    //     return "Hello World";
    // }
    return (...args) => "Hello World";
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
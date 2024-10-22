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
*/
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
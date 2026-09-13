// JavaScript: Demonstrating Type Systems, Scoping, and Closures
// Program: A configurable discount calculator using closures

// --- Type System Demonstration ---
// JavaScript is dynamically typed with implicit type coercion.
let price = 100;         // number
let taxRate = 0.08;      // number
let label = "Widget";    // string

// Arithmetic works as expected with numbers
let total = price + (price * taxRate);
console.log(`Item: ${label}, Price with tax: ${total}, Type: ${typeof total}`);

// Type coercion: the + operator concatenates when one operand is a string
let coerced = price + " dollars";
console.log(`Coerced result: ${coerced}, Type: ${typeof coerced}`);

// Loose equality vs strict equality
console.log(`\n"5" == 5 (loose):  ${("5" == 5)}`);    // true (coercion)
console.log(`"5" === 5 (strict): ${("5" === 5)}`);     // false (no coercion)


// --- Closures Demonstration ---
// A closure captures variables from its enclosing lexical scope.
function makeDiscountCalculator(discountPercent) {
    // Returns a closure that remembers 'discountPercent'
    return function(originalPrice) {
        let savings = originalPrice * (discountPercent / 100);
        return originalPrice - savings;
    };
}

let tenPercentOff = makeDiscountCalculator(10);
let twentyFiveOff = makeDiscountCalculator(25);

console.log(`\n10% off $80: $${tenPercentOff(80).toFixed(2)}`);
console.log(`25% off $80: $${twentyFiveOff(80).toFixed(2)}`);


// --- Scoping Demonstration ---
// JavaScript has function scope (var) and block scope (let/const)
var globalVar = "I am global (var)";

function outerFunction() {
    let enclosingVar = "I am in the enclosing scope (let)";

    function innerFunction() {
        let localVar = "I am local (let)";
        console.log(`  Inner sees localVar: ${localVar}`);
        console.log(`  Inner sees enclosingVar: ${enclosingVar}`);
        console.log(`  Inner sees globalVar: ${globalVar}`);
    }

    innerFunction();
    // localVar is NOT accessible here (block-scoped with let)
}

console.log("\nScoping demonstration:");
outerFunction();


// --- Block Scope: var vs let ---
// 'var' is function-scoped (leaks out of blocks)
for (var j = 0; j < 3; j++) {
    var loopVarVar = j;
}
console.log(`\nAfter loop (var): j = ${j}, loopVarVar = ${loopVarVar}`);

// 'let' is block-scoped (stays inside the block)
for (let k = 0; k < 3; k++) {
    let loopVarLet = k;
}
// Uncommenting the next line would cause a ReferenceError:
// console.log(`After loop (let): k = ${k}`);
console.log("After loop (let): k and loopVarLet are NOT accessible (block-scoped)");

// --- var hoisting demonstration ---
console.log(`\nHoisted varDemo before assignment: ${varDemo}`); // undefined, not an error
var varDemo = "now assigned";
console.log(`varDemo after assignment: ${varDemo}`);

// C++: Demonstrating Type Systems, Scoping, and Closures (Lambdas)
// Program: A configurable discount calculator using lambdas
#include <iostream>
#include <functional>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
    // --- Type System Demonstration ---
    // C++ is statically typed; types are checked at compile time.
    int price = 100;
    double taxRate = 0.08;
    string label = "Widget";

    // Implicit conversion: int * double promotes to double
    double total = price + (price * taxRate);
    cout << "Item: " << label << ", Price with tax: " << total
         << ", Type: " << typeid(total).name() << endl;

    // Static typing prevents reassignment to a different type:
    // price = "fifty";  // This would cause a compile-time error

    // Explicit casting is required for narrowing conversions
    int truncated = static_cast<int>(total);
    cout << "Truncated total (double to int): " << truncated << endl;

    // No loose equality operator; comparisons are type-strict
    // "5" == 5 would not compile because string and int are incompatible
    cout << "\nC++ does not allow comparing string to int directly." << endl;
    cout << "5 == 5 (same types): " << (5 == 5) << endl;


    // --- Closures (Lambdas) Demonstration ---
    // C++ uses lambda expressions; captured variables must be specified explicitly.
    auto makeDiscountCalculator = [](double discountPercent) -> function<double(double)> {
        // Capture 'discountPercent' by value
        return [discountPercent](double originalPrice) -> double {
            double savings = originalPrice * (discountPercent / 100.0);
            return originalPrice - savings;
        };
    };

    auto tenPercentOff = makeDiscountCalculator(10);
    auto twentyFiveOff = makeDiscountCalculator(25);

    cout << "\n10% off $80: $" << tenPercentOff(80) << endl;
    cout << "25% off $80: $" << twentyFiveOff(80) << endl;


    // --- Scoping Demonstration ---
    // C++ has block-level scoping for all variable declarations.
    string globalVar = "I am in main scope";

    {
        // This is an inner block
        string blockVar = "I am in an inner block";
        cout << "\nInside block: blockVar = " << blockVar << endl;
        cout << "Inside block: globalVar = " << globalVar << endl;
    }
    // blockVar is NOT accessible here; uncommenting would cause a compile error:
    // cout << blockVar << endl;
    cout << "Outside block: blockVar is NOT accessible (block-scoped)" << endl;


    // --- Block Scope in Loops ---
    // Loop variables are confined to the loop block
    for (int i = 0; i < 3; i++) {
        int loopVar = i;
    }
    // 'i' and 'loopVar' are NOT accessible here
    cout << "\nAfter loop: i and loopVar are NOT accessible (block-scoped)" << endl;

    // --- Variable shadowing ---
    int shadowVar = 10;
    cout << "\nBefore block, shadowVar = " << shadowVar << endl;
    {
        int shadowVar = 99;  // shadows the outer variable
        cout << "Inside block, shadowVar = " << shadowVar << endl;
    }
    cout << "After block, shadowVar = " << shadowVar << " (outer restored)" << endl;

    return 0;
}

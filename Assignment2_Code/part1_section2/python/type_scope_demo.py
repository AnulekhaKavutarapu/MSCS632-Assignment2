# Python: Demonstrating Type Systems, Scoping, and Closures
# Program: A configurable discount calculator using closures

# --- Type System Demonstration ---
# Python is dynamically typed; variable types are determined at runtime.
price = 100          # int
tax_rate = 0.08      # float
label = "Widget"     # str

# Implicit type coercion: int + float produces float
total = price + (price * tax_rate)
print(f"Item: {label}, Price with tax: {total}, Type: {type(total)}")

# Dynamic typing allows reassignment to a different type
price = "fifty"
print(f"Reassigned price to string: {price}, Type: {type(price)}")
price = 100  # reset for later use


# --- Closures Demonstration ---
# A closure captures variables from its enclosing scope.
def make_discount_calculator(discount_percent):
    """Factory function that returns a closure."""
    def apply_discount(original_price):
        # 'discount_percent' is captured from the enclosing scope
        savings = original_price * (discount_percent / 100)
        return original_price - savings
    return apply_discount

ten_percent_off = make_discount_calculator(10)
twenty_five_off = make_discount_calculator(25)

print(f"\n10% off $80: ${ten_percent_off(80):.2f}")
print(f"25% off $80: ${twenty_five_off(80):.2f}")


# --- Scoping Demonstration ---
# Python uses LEGB rule: Local, Enclosing, Global, Built-in
global_var = "I am global"

def outer_function():
    enclosing_var = "I am in the enclosing scope"

    def inner_function():
        local_var = "I am local"
        print(f"  Inner sees local_var: {local_var}")
        print(f"  Inner sees enclosing_var: {enclosing_var}")
        print(f"  Inner sees global_var: {global_var}")

    inner_function()
    # Uncommenting the next line would cause a NameError:
    # print(local_var)

print("\nScoping demonstration:")
outer_function()


# --- Block Scope Behavior ---
# Python does NOT have block-level scoping for if/for/while
for i in range(3):
    loop_var = i

# 'loop_var' and 'i' are still accessible here
print(f"\nAfter loop, i = {i}, loop_var = {loop_var}")

if True:
    block_var = "created inside if"

print(f"After if block, block_var = {block_var}")

// Rust: Memory Management via Ownership and Borrowing
// Compile: rustc memory_demo.rs -o memory_demo
// Run:     ./memory_demo

fn main() {
    println!("=== Rust Ownership and Borrowing Demo ===\n");

    // --- Ownership: each value has exactly one owner ---
    let original = String::from("Hello, Rust!");
    println!("Original string: {}", original);

    // Ownership moves to 'moved'; 'original' is no longer valid
    let moved = original;
    println!("After move, moved = {}", moved);
    // Uncommenting the next line would cause a compile-time error:
    // println!("{}", original); // ERROR: value used after move

    // --- Clone: deep copy to keep both values alive ---
    let first = String::from("deep copy");
    let second = first.clone();
    println!("\nCloned: first = {}, second = {}", first, second);

    // --- Borrowing: references without taking ownership ---
    let data = String::from("shared data");
    print_length(&data);           // immutable borrow
    println!("After borrow, data still valid: {}", data);

    // --- Mutable Borrowing ---
    let mut mutable_data = String::from("original");
    println!("\nBefore mutation: {}", mutable_data);
    append_exclamation(&mut mutable_data);  // mutable borrow
    println!("After mutation: {}", mutable_data);

    // --- Dynamic Allocation with Box (heap allocation) ---
    let heap_int = Box::new(42);
    println!("\nHeap-allocated integer: {}", heap_int);
    // When 'heap_int' goes out of scope, memory is freed automatically

    // --- Vector: dynamic array with automatic cleanup ---
    let mut numbers: Vec<i32> = Vec::new();
    for i in 0..5 {
        numbers.push(i * 10);
    }
    println!("Dynamic vector: {:?}", numbers);
    println!("Vector capacity: {}, length: {}", numbers.capacity(), numbers.len());

    // --- Scope-based deallocation ---
    {
        let temp = String::from("I will be freed at the end of this block");
        println!("\nInside scope: {}", temp);
    }
    // 'temp' is dropped here; its memory is freed automatically
    println!("Outside scope: temp has been freed (no dangling pointer possible)");

    println!("\n=== All memory freed automatically when variables go out of scope ===");
}

// Immutable borrow: reads data without taking ownership
fn print_length(s: &String) {
    println!("Length of '{}': {}", s, s.len());
}

// Mutable borrow: modifies data without taking ownership
fn append_exclamation(s: &mut String) {
    s.push_str("!!!");
}

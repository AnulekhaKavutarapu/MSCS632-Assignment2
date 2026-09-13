// C++: Memory Management via Manual Allocation (new/delete)
// Compile: g++ -std=c++17 -o memory_demo memory_demo.cpp
// Run:     ./memory_demo
// Profile: valgrind --tool=memcheck --leak-check=full ./memory_demo

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// A simple class to track construction and destruction
class DataBlock {
public:
    string label;
    int* payload;
    int size;

    DataBlock(const string& lbl, int sz) : label(lbl), size(sz) {
        payload = new int[sz];  // manually allocate array on the heap
        for (int i = 0; i < sz; i++) {
            payload[i] = i;
        }
        cout << "  Constructed: " << label << " (size: " << sz << ")" << endl;
    }

    ~DataBlock() {
        delete[] payload;  // manually free the array
        cout << "  Destroyed: " << label << endl;
    }
};

int main() {
    cout << "=== C++ Manual Memory Management Demo ===" << endl << endl;

    // --- Manual allocation with new/delete ---
    cout << "--- Manual new/delete ---" << endl;
    DataBlock* block1 = new DataBlock("Block-A", 1000);
    DataBlock* block2 = new DataBlock("Block-B", 1000);

    cout << "Using " << block1->label << " and " << block2->label << endl;

    // Must manually free; forgetting causes a memory leak
    delete block1;
    delete block2;
    cout << "Both blocks deleted manually." << endl;

    // --- Dangling pointer demonstration ---
    cout << "\n--- Dangling pointer risk ---" << endl;
    int* dangling = new int(42);
    cout << "Value before delete: " << *dangling << endl;
    delete dangling;
    // dangling now points to freed memory
    // Accessing *dangling here is undefined behavior
    dangling = nullptr;  // Best practice: set to nullptr after delete
    cout << "Pointer set to nullptr after delete (safe practice)." << endl;

    // --- Memory leak demonstration (intentional) ---
    cout << "\n--- Intentional memory leak ---" << endl;
    int* leaked = new int[500];
    for (int i = 0; i < 500; i++) {
        leaked[i] = i;
    }
    cout << "Allocated 500 ints on the heap." << endl;
    // Intentionally NOT deleting 'leaked' to demonstrate a leak
    // In production code, this would be: delete[] leaked;
    cout << "Skipping delete[] to demonstrate a memory leak." << endl;
    cout << "(Valgrind would report this as 2000 bytes lost)" << endl;

    // --- Smart pointers: modern C++ solution ---
    cout << "\n--- Smart pointers (unique_ptr) ---" << endl;
    {
        unique_ptr<DataBlock> smartBlock = make_unique<DataBlock>("Smart-Block", 500);
        cout << "Using smart pointer: " << smartBlock->label << endl;
        // No manual delete needed; unique_ptr frees memory at end of scope
    }
    cout << "Smart block automatically destroyed at end of scope." << endl;

    // --- Dynamic array with smart pointer ---
    cout << "\n--- Smart pointer array ---" << endl;
    {
        unique_ptr<int[]> smartArray = make_unique<int[]>(100);
        for (int i = 0; i < 100; i++) {
            smartArray[i] = i * 2;
        }
        cout << "Smart array[50] = " << smartArray[50] << endl;
    }
    cout << "Smart array automatically freed." << endl;

    cout << "\n=== Manual management requires discipline; smart pointers help ===" << endl;
    return 0;
}

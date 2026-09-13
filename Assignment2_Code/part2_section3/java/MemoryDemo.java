// Java: Memory Management via Garbage Collection
// Compile: javac MemoryDemo.java
// Run:     java -verbose:gc MemoryDemo

import java.util.ArrayList;

public class MemoryDemo {

    // A simple class to demonstrate heap allocation
    static class DataBlock {
        private int[] payload;
        private String label;

        public DataBlock(String label, int size) {
            this.label = label;
            this.payload = new int[size];
            // Fill array to ensure memory is actually used
            for (int i = 0; i < size; i++) {
                payload[i] = i;
            }
        }

        @Override
        protected void finalize() throws Throwable {
            System.out.println("  GC finalized: " + label);
            super.finalize();
        }

        @Override
        public String toString() {
            return label + " (size: " + payload.length + ")";
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Java Garbage Collection Demo ===\n");

        // --- Objects are always allocated on the heap ---
        DataBlock block1 = new DataBlock("Block-A", 1000);
        DataBlock block2 = new DataBlock("Block-B", 1000);
        System.out.println("Created: " + block1);
        System.out.println("Created: " + block2);

        // Show initial memory usage
        Runtime rt = Runtime.getRuntime();
        long usedBefore = rt.totalMemory() - rt.freeMemory();
        System.out.println("\nMemory used after allocation: " + usedBefore + " bytes");

        // --- Nullifying references makes objects eligible for GC ---
        block1 = null;
        block2 = null;
        System.out.println("\nReferences set to null (objects eligible for GC)");

        // --- Request garbage collection (not guaranteed to run immediately) ---
        System.out.println("Requesting garbage collection...");
        System.gc();

        // Small delay to give GC a chance to run
        try { Thread.sleep(500); } catch (InterruptedException e) {}

        long usedAfter = rt.totalMemory() - rt.freeMemory();
        System.out.println("Memory used after GC: " + usedAfter + " bytes");
        System.out.println("Memory reclaimed: " + (usedBefore - usedAfter) + " bytes");

        // --- Demonstrate dynamic list growth ---
        System.out.println("\n--- Dynamic ArrayList growth ---");
        ArrayList<DataBlock> list = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            list.add(new DataBlock("Item-" + i, 5000));
        }
        System.out.println("Created " + list.size() + " objects in ArrayList");

        long usedWithList = rt.totalMemory() - rt.freeMemory();
        System.out.println("Memory used with list: " + usedWithList + " bytes");

        // Clear the list; objects become eligible for GC
        list.clear();
        list = null;
        System.gc();
        try { Thread.sleep(500); } catch (InterruptedException e) {}

        long usedAfterClear = rt.totalMemory() - rt.freeMemory();
        System.out.println("Memory used after clearing list and GC: " + usedAfterClear + " bytes");

        // --- No manual free; no dangling pointers; no memory leaks (in typical use) ---
        System.out.println("\n=== Java handles deallocation automatically via GC ===");
        System.out.println("No manual free(), no dangling pointers, no double-free errors.");
    }
}

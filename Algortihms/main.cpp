#include <iostream>
#include "wrapper.hpp"
/**
 * List of Various Available Algorithmic Approaches
 * Searching Algorithms
 *** Linear Search
 *** Binary Search

 * Sorting Algorithms
 *** Bubble Sort
 *** Insertion Sort
 *** Selection Sort
 *** Merge Sort
 *** Quick Sort
 *** Radix Sort
 *** External Sort

 * Greedy Approach
 *** Knapsack Problem - Fractional | 0-1
 *** Machine Scheduling

 * Fibonacci
 * Maximum Contiguous Sub-sequence Sum
 */

/**
 * Fibonacci using DP
 * Max Continuous Sub-sequence Sum - DP
 * All Pair Shortest Path - DP
 * 0 | 1 Knapsack
 */

int main(void)
{
    int op;
    // Create options here to use each algorithm
    std::cout << "Available Options:" << std::endl
         << "0 - Searching Algorithms" << std::endl
         << "1 - Sorting Algorithms" << std::endl
         << "2 - Greedy Approaches" << std::endl;
    op = wrapper::inputOption<int>();
    int retVal;
    if(op == 0) {
        wrapper::clearScreen();
        retVal = wrapper::searchWrapper();
    }
    else if(op == 1) {
        wrapper::clearScreen();
        retVal = wrapper::sortWrapper();
    }
    else if(op == 2) {
        wrapper::clearScreen();
        retVal = wrapper::greedyWrapper();
    }
    return 0;
}
